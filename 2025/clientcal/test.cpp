#include<iostream>

#include"protocol.hpp"

#include"socket.hpp"

#define SIZE 1024

#include<time.h>

int main()
{
    srand(time(NULL));
    sock sk;
    sk.my_socket();
    sk.my_connect("127.0.0.1", 8080);

    std::string opstr = "+-*/%=&";
    char buffer[SIZE] = { 0 };
    int cnt = 5;
    while (cnt--)
    {
        // char buffer[SIZE] = {0};
        sleep(1);
        Request rq;
        std::string message;
        rq._a = rand() % 100;
        rq._b = rand() % 100;
        rq._op = opstr[rand() % 7];
        std::cout << rq._a << " " << rq._op << " " << rq._b << std::endl;
        rq.Serialization(message);
        std::string content = encode(message);
        write(sk.get_sockfd(), content.c_str(), content.size());
        ssize_t ret = read(sk.get_sockfd(), buffer, SIZE);
        if (ret > 0)
        {
            buffer[ret] = 0;
            std::string buf = buffer;
            Response rp;
            std::string tmp;
            decode(buf, tmp);
            rp.Deserialization(tmp);
            std::cout << rp._result << " " << rp._status_code << std::endl;
        }
    }

    return 0;
}