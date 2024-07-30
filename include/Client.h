#pragma once

#include <sys/socket.h>
#include <memory>
#include <vector>
#include <thread>
#include "IMessage.h"
#include "SocketConnection.h"

class Client {
public:
    Client(int port, char *ip);

    ~Client();

    void setMessage(std::string &name, std::string &data);

    void sendMessage();

    void receiveMessage();

    void handler();

private:
    std::vector<std::thread> threads;
    std::mutex mutex;
    std::unique_ptr<IMessage> message{};

    SocketConnection socket;
    int port{};
    std::string ip;
};

