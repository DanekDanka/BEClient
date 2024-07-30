#include <iostream>
#include "Client.h"
#include "Fabric.h"

Client::Client(int port, char *ip) {
    message = Fabric::createMessage();
    socket.init(port, ip);
}

Client::~Client() = default;

void Client::setMessage(std::string &name, std::string &data) {
    message->setName(name);
    message->setData(data);
}

void Client::sendMessage() {
    socket.send((message->getName() + message->getData()).data());
}

void Client::receiveMessage() {
    char buff[1024];
    socket.receive(buff);
    std::cout << buff << std::endl;
}

void Client::handler() {
    threads.emplace_back([&] {
        while (true) {
            mutex.lock();
            receiveMessage();
            mutex.unlock();
        }
    });

    while (true) {
        std::cout << "Введите мия ресурса и данные" << std::endl;

        std::string name;
        std::string data;

        std::cin >> name;
        if (name == "exit") {
            exit(EXIT_SUCCESS);
        }

        getline(std::cin, data);

        setMessage(name, data);
        sendMessage();
    }

}


