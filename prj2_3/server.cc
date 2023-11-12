#include "Message.hpp"
#include <array>
#include <cstddef>
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void error(const char *msg) {
    std::cerr << msg << std::endl;
    exit(-1);
}

int main(int argc, char *argv[]) {
    int sock, length, n;
    socklen_t fromlen;
    sockaddr_in server;
    sockaddr_in from;
    char buf[1024];

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(0);
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        error("Opening socket");
    length = sizeof(server);
    bzero(&server, length);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));
    if (bind(sock, (sockaddr *)&server, length) < 0)
        error("binding");
    fromlen = sizeof(sockaddr_in);
    Message rcv;
    while (1) {

        n = recvfrom(sock, (char *)&rcv, sizeof(Message), 0, (sockaddr *)&from,
                     &fromlen);
        if (n < 0)
            error("recvfrom");
        std::cout << "Received a datagram" << std::endl
                  << rcv.msgAsString() << std::endl;

        n = sendto(sock, (char *)&rcv, sizeof(Message), 0, (sockaddr *)&from,
                   fromlen);
        if (n < 0)
            error("sendto");
    }
    return 0;
}
