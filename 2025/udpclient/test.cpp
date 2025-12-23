#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<iostream>

#include<stdio.h>

#include<string>

#include <sys/types.h>

#include<string.h>

#include <winsock2.h>

#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib") // 自动链接Winsock库

#define SIZE 1024

enum
{
    SOCKETERR = 1,
    BINDERR,
    ARGCERR
};

std::string ip = "8.148.76.120";

int main()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData); // 请求WinSock 2.2版本
    if (iResult != 0) {
        std::cout << "WSAStartup failed: " << iResult << std::endl;
        return 1;
    }

    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(SOCKETERR);
    }

    sockaddr_in in;
    memset(&in, 0, sizeof(in));

    uint16_t serverport = 8080;
    in.sin_addr.s_addr = inet_addr(ip.c_str());
    in.sin_family = AF_INET;
    in.sin_port = htons(serverport);

    char buffer[SIZE] = { 0 };
    std::string message;
    while (1)
    {
        std::cout << "please enter# ";
        std::getline(std::cin, message);
        if (sendto(sockfd, message.c_str(), message.size(), 0, (sockaddr*)&in, sizeof(in)) < 0)
        {
            perror("sendto");
        }

        sockaddr_in temp;
        socklen_t len = sizeof(temp);

        int ret = recvfrom(sockfd, buffer, SIZE, 0, (sockaddr*)&temp, &len);

        buffer[ret] = 0;

        if (ret > 0) std::cout << buffer << std::endl;
    }

    closesocket(sockfd);

    WSACleanup();
    return 0;
}