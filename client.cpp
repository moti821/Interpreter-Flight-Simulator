#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "client.hpp"

Client *Client::instance = 0;

Client *Client::getInstance()
{
    if (instance == 0)
    {
        instance = new Client();
    };
    return instance;
}
Client::Client() {}

void Client::connect(int port, std::string ip)
{

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "Socket creation error" << std::endl;
        return;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);

    if (::connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        std::cout << "Connection Failed" << std::endl;
        return;
    }
}

void Client::send(std::string path, double value)
{
    std::string string_value = std::to_string(value); 
    std::string message_is = "set " + path + " " + string_value + "\r\n";
    char *command = &message_is[0];
    ::send(sock, command, strlen(command), 0);
    valread = read(sock, buffer, 1024);
}
