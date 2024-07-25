#pragma once

#include <sys/socket.h>
#include <memory>
#include <vector>
#include <thread>
#include "IMessage.h"
#include "Sender.h"
#include "Recevier.h"

class Client {
public:
    Client(int port, char * ip);
    ~Client();

    void setMessage(std::string &name, std::string &data);
    void sendMessage();
    void receiveMessage();
    void handler();

private:
    std::vector<std::thread> threads;
    std::mutex mutex;
    std::unique_ptr<IMessage> message {};
    Sender sender;
    Recevier receiver;
    int port{};
    std::string ip;
};

