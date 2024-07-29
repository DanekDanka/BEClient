
// Server side implementation of UDP client-server model
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "Client.h"

#define PORT     8080
#define MAXLINE 1024

// 0    ip
// 1    port
int main(int argc, char* argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Введено неправильное количество параметров\nВведите: <ip получателя> <port>");
        return 0;
    }

    Client client(atoi(argv[2]), argv[1]);

    client.handler();

    return 0;
}

