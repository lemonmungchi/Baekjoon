#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <chrono>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")  // Winsock ���̺귯�� ��ũ

// ĳ���� ����ü ����
struct Character {
    std::string name;
    int x, y;
    int health = 500;
    int attackPower = 10;
};

// �޽��� Ÿ�� ����
enum MessageType {
    CONNECTION_REQUEST = 0x00,
    POSITION_UPDATE = 0x01,
    ACTION_COMMAND = 0x02,
    STATUS_UPDATE = 0x03
};

// �޽��� ����ü ����
struct Message {
    MessageType type;
    uint32_t data_length;
    char data[256];
};

// ���� Ŭ���� ����
class GameServer {
public:
    std::map<int, Character> players;
    int client_counter = 0;

    // �޽��� ó�� �Լ�
    void processMessage(int clientID, Message message) {
        switch (message.type) {
        case CONNECTION_REQUEST:
            // ���� ��û ó��
            players[clientID].name = std::string(message.data);
            std::cout << "Player connected: " << players[clientID].name << std::endl;
            break;
        case POSITION_UPDATE:
            // ��ġ ������Ʈ ó��
            int x, y;
            sscanf_s(message.data, "%d %d", &x, &y);
            players[clientID].x = x;
            players[clientID].y = y;
            std::cout << "Player " << clientID << " moved to (" << x << ", " << y << ")\n";
            break;
        case ACTION_COMMAND:
            // ���� ��� ó��
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

    // Ŭ���̾�Ʈ�� ���� ����
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
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);  // Winsock �ʱ�ȭ
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }

    SOCKET sockfd;
    sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);

    // ���� ����
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // ���ε�
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

        // 20ms���� ���� ������Ʈ ����
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        gameServer.broadcastState(sockfd, client_addr, addr_len);
    }

    closesocket(sockfd);  // ���� �ݱ�
    WSACleanup();  // Winsock ����
    return 0;
}
