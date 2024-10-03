#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>  // inet_pton �Լ� ����� ���� �ʿ�

#pragma comment(lib, "Ws2_32.lib")  // Winsock ���̺귯�� ��ũ

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

// Ŭ���̾�Ʈ �Լ�
void sendMessage(SOCKET sockfd, sockaddr_in server_addr, Message message) {
    sendto(sockfd, (char*)&message, sizeof(message), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
}

// �������� �޽��� ����
Message receiveMessage(SOCKET sockfd) {
    Message message;
    recvfrom(sockfd, (char*)&message, sizeof(message), 0, nullptr, nullptr);
    return message;
}

int main() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);  // Winsock �ʱ�ȭ
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }

    SOCKET sockfd;
    sockaddr_in server_addr;

    // ���� ����
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    // inet_pton�� ����Ͽ� IP �ּ� ��ȯ
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // ĳ���� �̸� ���� �� ���� ���� ��û
    std::string playerName;
    std::cout << "Enter your character name: ";
    std::cin >> playerName;

    Message connectMessage;
    connectMessage.type = CONNECTION_REQUEST;
    strncpy_s(connectMessage.data, sizeof(connectMessage.data), playerName.c_str(), playerName.size());
    connectMessage.data_length = playerName.size();
    sendMessage(sockfd, server_addr, connectMessage);

    while (true) {
        std::cout << "1. Move\n2. Attack\nChoose an action: ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // ��ġ ������Ʈ
            int x, y;
            std::cout << "Enter new coordinates (x y): ";
            std::cin >> x >> y;
            Message moveMessage;
            moveMessage.type = POSITION_UPDATE;
            snprintf(moveMessage.data, sizeof(moveMessage.data), "%d %d", x, y);
            moveMessage.data_length = strlen(moveMessage.data);
            sendMessage(sockfd, server_addr, moveMessage);
        }
        else if (choice == 2) {
            // ���� ���
            int targetID;
            std::cout << "Enter target player ID: ";
            std::cin >> targetID;
            Message attackMessage;
            attackMessage.type = ACTION_COMMAND;
            snprintf(attackMessage.data, sizeof(attackMessage.data), "%d", targetID);
            attackMessage.data_length = strlen(attackMessage.data);
            sendMessage(sockfd, server_addr, attackMessage);
        }

        // �����κ��� ���� ������Ʈ ����
        Message serverMessage = receiveMessage(sockfd);
        if (serverMessage.type == STATUS_UPDATE) {
            std::cout << "Game State:\n" << serverMessage.data << std::endl;
        }
    }

    closesocket(sockfd);  // ���� �ݱ�
    WSACleanup();  // Winsock ����
    return 0;
}
