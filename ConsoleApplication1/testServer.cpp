#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <thread>  // 스레드 사용
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>

// 캐릭터 구조체 정의
struct Character {
    std::string name;
    int x = 0, y = 0;
    int health = 500;
    int attackPower = 10;
};

// 메시지 타입 정의
enum MessageType {
    CONNECTION_REQUEST = 0x00,
    POSITION_UPDATE = 0x01,
    ACTION_COMMAND = 0x02,
    STATUS_UPDATE = 0x03,
    PING_REQUEST = 0x04,
    PING_RESPONSE = 0x05
};

// 메시지 구조체 정의
struct Message {
    MessageType type;
    uint32_t data_length;
    char data[256];
};

// sockaddr_in 구조체를 비교하기 위한 함수 (IP와 포트 번호를 함께 비교)
bool compareSockaddr(const sockaddr_in& a, const sockaddr_in& b) {
    return a.sin_addr.s_addr == b.sin_addr.s_addr && a.sin_port == b.sin_port;
}

// 서버 클래스 정의
class GameServer {
public:
    std::map<int, Character> players;
    std::vector<sockaddr_in> client_addresses;
    int client_counter = 0;

    // 클라이언트 ID 할당
    int getClientID(sockaddr_in client_addr) {
        for (size_t i = 0; i < client_addresses.size(); ++i) {
            if (compareSockaddr(client_addresses[i], client_addr)) {
                return i;
            }
        }
        client_addresses.push_back(client_addr);
        return client_counter++;
    }

    // 메시지 처리 함수 (스레드 내에서 실행)
    void handleClient(SOCKET sockfd, sockaddr_in client_addr, Message message, int addr_len) {
        int clientID = getClientID(client_addr);
        processMessage(clientID, message);
        broadcastState(sockfd, addr_len);  // 다른 클라이언트에 상태 브로드캐스트
    }

    void processMessage(int clientID, Message message) {
        switch (message.type) {
        case CONNECTION_REQUEST:
            players[clientID].name = std::string(message.data);
            std::cout << "Player connected: " << players[clientID].name << std::endl;
            break;
        case POSITION_UPDATE:
            int x, y;
            sscanf(message.data, "%d %d", &x, &y);
            players[clientID].x = x;
            players[clientID].y = y;
            std::cout << "Player " << clientID << " moved to (" << x << ", " << y << ")\n";
            break;
        case ACTION_COMMAND:
            int targetID;
            sscanf(message.data, "%d", &targetID);
            if (players.find(targetID) != players.end()) {
                players[targetID].health -= players[clientID].attackPower;
                std::cout << "Player " << clientID << " attacked Player " << targetID << std::endl;
            }
            break;
        default:
            break;
        }
    }

    // 모든 클라이언트에 상태 전송
    void broadcastState(SOCKET sockfd, int addr_len) {
        Message message;
        message.type = STATUS_UPDATE;
        std::string status;
        for (const auto& player : players) {
            status += player.second.name + ": (" + std::to_string(player.second.x) + ", " +
                std::to_string(player.second.y) + ") HP: " + std::to_string(player.second.health) + "\n";
        }
        strncpy(message.data, status.c_str(), sizeof(message.data) - 1);
        message.data[sizeof(message.data) - 1] = '\0';

        // 각 클라이언트에 상태 정보 전송
        for (const auto& client_addr : client_addresses) {
            sendto(sockfd, (char*)&message, sizeof(message), 0, (struct sockaddr*)&client_addr, addr_len);
        }
    }
};

// 서버 메인 코드
int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed" << std::endl;
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
    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    GameServer gameServer;

    // 메인 루프
    while (true) {
        Message message;
        recvfrom(sockfd, (char*)&message, sizeof(message), 0, (struct sockaddr*)&client_addr, &addr_len);

        // 각 클라이언트 메시지를 별도의 스레드에서 처리
        std::thread clientThread(&GameServer::handleClient, &gameServer, sockfd, client_addr, message, addr_len);
        clientThread.detach();  // 스레드가 종료되면 자동으로 자원 반환
    }

    closesocket(sockfd);
    WSACleanup();
    return 0;
}
