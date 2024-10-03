#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <chrono>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")  // Winsock 라이브러리 링크

// 캐릭터 구조체 정의
struct Character {
    std::string name;
    int x, y;
    int health = 500;
    int attackPower = 10;
};

// 메시지 타입 정의
enum MessageType {
    CONNECTION_REQUEST = 0x00,
    POSITION_UPDATE = 0x01,
    ACTION_COMMAND = 0x02,
    STATUS_UPDATE = 0x03
};

// 메시지 구조체 정의
struct Message {
    MessageType type;
    uint32_t data_length;
    char data[256];
};

// 서버 클래스 정의
class GameServer {
public:
    std::map<int, Character> players;
    int client_counter = 0;

    // 메시지 처리 함수
    void processMessage(int clientID, Message message) {
        switch (message.type) {
        case CONNECTION_REQUEST:
            // 연결 요청 처리
            players[clientID].name = std::string(message.data);
            std::cout << "Player connected: " << players[clientID].name << std::endl;
            break;
        case POSITION_UPDATE:
            // 위치 업데이트 처리
            int x, y;
            sscanf_s(message.data, "%d %d", &x, &y);
            players[clientID].x = x;
            players[clientID].y = y;
            std::cout << "Player " << clientID << " moved to (" << x << ", " << y << ")\n";
            break;
        case ACTION_COMMAND:
            // 공격 명령 처리
            int targetID;
            sscanf_s(message.data, "%d", &targetID);
            if (players.find(targetID) != players.end()) {
                players[targetID].health -= players[clientID].attackPower;
                std::cout << "Player " << clientID << " attacked Player " << targetID << std::endl;
            }
            break;
        default:
            break;
        }
    }

    // 클라이언트에 상태 전송
    void broadcastState(SOCKET sockfd, sockaddr_in client_addr, int addr_len) {
        Message message;
        message.type = STATUS_UPDATE;
        std::string status;
        for (const auto& player : players) {
            status += player.second.name + ": (" + std::to_string(player.second.x) + ", " +
                std::to_string(player.second.y) + ") HP: " + std::to_string(player.second.health) + "\n";
        }
        strncpy_s(message.data, sizeof(message.data), status.c_str(), status.size());
        message.data_length = status.size();
        sendto(sockfd, (char*)&message, sizeof(message), 0, (struct sockaddr*)&client_addr, addr_len);
    }
};

int main() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);  // Winsock 초기화
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }

    SOCKET sockfd;
    sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);

    // 소켓 생성
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // 바인딩
    result = bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (result == SOCKET_ERROR) {
        std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    GameServer gameServer;

    while (true) {
        Message message;
        recvfrom(sockfd, (char*)&message, sizeof(message), 0, (struct sockaddr*)&client_addr, &addr_len);

        int clientID = gameServer.client_counter++;
        gameServer.processMessage(clientID, message);

        // 20ms마다 상태 업데이트 전송
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        gameServer.broadcastState(sockfd, client_addr, addr_len);
    }

    closesocket(sockfd);  // 소켓 닫기
    WSACleanup();  // Winsock 종료
    return 0;
}
