#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>
#include <unistd.h>
#include "Sender.h"

Sender::Sender() {}

Sender::~Sender() {

}

void Sender::init(int PORT, const char *ip) {
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        fprintf(stderr, "[ERROR] Socket creation failed\n");
        exit(EXIT_FAILURE);
    }


    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
//    servaddr.sin_addr.s_addr = inet_addr(ip);
    servaddr.sin_addr.s_addr = INADDR_ANY;
}

void Sender::send(const char *data) {
    sendto(sockfd, data, strlen(data), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    fprintf(stdout, "Message sent\n");
}

void Sender::receive(char *buffer) {
    size_t n = 0;
    socklen_t len;
    n = recvfrom(sockfd, buffer, maxlen, MSG_WAITALL, (struct sockaddr*)&servaddr, &len);
    buffer[n] = '\0';
    fprintf(stdout, "Message received\n");
}

void Sender::endCommunication() {
    close(sockfd);
}
