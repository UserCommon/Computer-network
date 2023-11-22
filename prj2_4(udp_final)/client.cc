#include "Message.hpp"
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sock, n;
    unsigned int length;
    sockaddr_in server, from;
    hostent *hp;
    char buffer[1024];

    if (argc != 3) {
        printf("Usage: server port\n");
        exit(1);
    }
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
        error("socket");

    server.sin_family = AF_INET;
    hp = gethostbyname(argv[1]);
    if (hp == 0)
        error("Unknown host");

    bcopy((char *)hp->h_addr, (char *)&server.sin_addr, hp->h_length);
    server.sin_port = htons(atoi(argv[2]));
    length = sizeof(sockaddr_in);
    char name[25];
    double weight, height;

    while (1) {
        std::cout << "Enter name" << std::endl;
        std::cin >> name;
        if (memcmp(name, "exit", strlen("exit")) == 0) {
            break;
        }
        std::cout << "Enter weight" << std::endl;
        std::cin >> weight;
        std::cout << "Enter height" << std::endl;
        std::cin >> height;
        Message m(name, weight, height);

        n = sendto(sock, (char *)&m, sizeof(m), 0, (sockaddr *)&server, length);
        if (n < 0)
            error("Sendto");
        Message rcv;
        n = recvfrom(sock, (char *)&rcv, sizeof(Message), 0, (sockaddr *)&from,
                     &length);
        if (n < 0)
            error("recvfrom");
        std::cout << rcv.getBMIResult() << std::endl;
    }
    close(sock);
    return 0;
}
