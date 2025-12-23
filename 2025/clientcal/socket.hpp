#include<iostream>

#include<string>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include<unistd.h>

#include<string.h>

std::string defaultip = "127.0.0.1";
int16_t defaultport = 8080;

enum
{
    SOCKETERR = 1,
    LISTENERR,
    BINDERR,
    ACCEPTERR,
    CONNECTERR
};

class sock
{
public:
    sock()
    {
    }

    void my_socket()
    {
        _sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (_sockfd < 0)
        {
            perror("socket");
            exit(SOCKETERR);
        }

        int opt = 1;
        setsockopt(_sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)); // 防止偶发性的服务器无法进行立即重启(tcp协议的时候再说)
    }

    void my_bind(int16_t port)
    {
        sockaddr_in cli_in;
        memset((void*)&cli_in, 0, sizeof(cli_in));
        cli_in.sin_addr.s_addr = inet_addr(defaultip.c_str());
        cli_in.sin_family = AF_INET;
        cli_in.sin_port = htons(port);
        int ret = bind(_sockfd, (const sockaddr*)&cli_in, sizeof(cli_in));
        if (ret < 0)
        {
            perror("bind");
            exit(BINDERR);
        }
    }

    void my_listen()
    {
        int ret = listen(_sockfd, 5);
        if (ret < 0)
        {
            perror("listen");
            exit(LISTENERR);
        }
    }

    int my_accept(std::string& clientip, int16_t& clientport)
    {
        sockaddr_in get;
        memset((void*)&get, 0, sizeof(get));
        socklen_t glen = sizeof(get);
        int ret = accept(_sockfd, (sockaddr*)&get, &glen);
        if (ret < 0)
        {
            perror("accept");
            return -1;
        }

        char ipstr[64] = { 0 };
        clientip = inet_ntop(AF_INET, (const sockaddr*)&get.sin_addr, ipstr, sizeof(ipstr));
        clientip = ipstr;
        clientport = get.sin_port;

        return ret;
    }

    bool my_connect(const std::string& ip, const int16_t& port)
    {
        sockaddr_in ser_in;
        memset((void*)&ser_in, 0, sizeof(ser_in));
        ser_in.sin_addr.s_addr = inet_addr(ip.c_str());
        ser_in.sin_family = AF_INET;
        ser_in.sin_port = htons(port);
        int ret = connect(_sockfd, (const sockaddr*)&ser_in, sizeof(ser_in));
        if (ret < 0)
        {
            perror("accept");
            return false;
        }
        return true;
    }

    ~sock()
    {
    }

    void my_close()
    {
        close(_sockfd);
    }

    int get_sockfd()
    {
        return _sockfd;
    }

private:
    int _sockfd;
};