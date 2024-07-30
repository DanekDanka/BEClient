
#include <bits/stdc++.h>
#include <stdlib.h>
#include "Client.h"

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        fprintf(stderr, "Введено неправильное количество параметров\nВведите: <ip получателя> <port>");
        return 0;
    }

    Client client(atoi(argv[2]), argv[1]);

    client.handler();

    return 0;
}

