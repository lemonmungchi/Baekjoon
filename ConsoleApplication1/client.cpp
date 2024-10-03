#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>  // inet_pton 함수 사용을 위해 필요

#pragma comment(lib, "Ws2_32.lib")  // Winsock 라이브러리 링크

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

// 클라이언트 함수
void sendMessage(SOCKET sockfd, sockaddr_in server_addr, Message message) {
    sendto(sockfd, (char*)&message, sizeof(message), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
}

// 서버에서 메시지 수신
Message receiveMessage(SOCKET sockfd) {
    Message message;
    recvfrom(sockfd, (char*)&message, sizeof(message), 0, nullptr, nullptr);
    return message;
}

int main() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);  // Winsock 초기화
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }

    SOCKET sockfd;
    sockaddr_in server_addr;

    // 소켓 생성
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == INVALID_SOCKET) {
        std::cerr << "Socket creation failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);

    // inet_pton을 사용하여 IP 주소 변환
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        std::cerr << "Invalid address/ Address not supported" << std::endl;
        closesocket(sockfd);
        WSACleanup();
        return 1;
    }

    // 캐릭터 이름 설정 및 서버 연결 요청
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
            // 위치 업데이트
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
            // 공격 명령
            int targetID;
            std::cout << "Enter target player ID: ";
            std::cin >> targetID;
            Message attackMessage;
            attackMessage.type = ACTION_COMMAND;
            snprintf(attackMessage.data, sizeof(attackMessage.data), "%d", targetID);
            attackMessage.data_length = strlen(attackMessage.data);
            sendMessage(sockfd, server_addr, attackMessage);
        }

        // 서버로부터 상태 업데이트 수신
        Message serverMessage = receiveMessage(sockfd);
        if (serverMessage.type == STATUS_UPDATE) {
            std::cout << "Game State:\n" << serverMessage.data << std::endl;
        }
    }

    closesocket(sockfd);  // 소켓 닫기
    WSACleanup();  // Winsock 종료
    return 0;
}
