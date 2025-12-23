#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include<iostream>

#include<stdio.h>

#include<string>

#include <sys/types.h>

#include<string.h>

#include<vector>

#include <winsock2.h>

#include <windows.h>

#include <thread>

#pragma comment(lib, "ws2_32.lib") // Á´½ÓWinsock¿â

#define SIZE 1024

struct task
{
    int skfd;
    sockaddr_in in;
};

void* read_thread(void* arg)
{
    task* tkptr = static_cast<task*>(arg);

    char buffer[SIZE] = { 0 };
    while (1)
    {
        int n = recv(tkptr->skfd, buffer, SIZE, 0);
        if (n > 0)
        {
            buffer[n] = 0;
            std::cerr << buffer << std::endl;
        }
    }
}

int main(int argc, char* argv[])
{
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        return 1;
    }

    //if (argc != 3)
    //{
    //    std::cout << "3 words! error." << std::endl;
    //}

    task tk;
    tk.skfd = socket(AF_INET, SOCK_STREAM, 0);
    int16_t port = 8080;
    tk.in.sin_family = AF_INET;
    tk.in.sin_port = htons(port);
    tk.in.sin_addr.s_addr = inet_addr("8.148.76.120");

    connect(tk.skfd, (const sockaddr*)&(tk.in), sizeof(tk.in));

    std::thread t(read_thread, (void*)&tk);
    t.detach();

    std::string message;
    while (1)
    {
        std::cout << "please enter# ";
        std::getline(std::cin, message);
        send(tk.skfd, message.c_str(), message.size(), 0);
    }

    closesocket(tk.skfd);
    WSACleanup();
}