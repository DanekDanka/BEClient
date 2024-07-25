#include <iostream>
#include <cstring>
#include "Receiver.h"


void Receiver::init(int port) {
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        fprintf(stderr, "[ERROR] Socket creation failed\n");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (const struct sockaddr *) &servaddr,
             sizeof(servaddr)) < 0) {
        fprintf(stderr, "[ERROR] Bind failed\n");
        exit(EXIT_FAILURE);
    }

}

void Receiver::receive(char * buff) {
    socklen_t len;
    int n;

    len = sizeof(cliaddr);

    n = recvfrom(sockfd, (char *) buff, 1024,
                 MSG_WAITALL, (struct sockaddr *) &cliaddr,
                 &len);
    buff[n] = '\0';
}
