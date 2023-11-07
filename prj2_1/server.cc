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

void to_valid_buffer(char *buffer, unsigned int size) {
    // Warning! this function mutating buffer!
    for (unsigned int i = 0; i < size - 1; ++i) {
        if (buffer[i] == 0) {
            buffer[i] = '\0';
            return;
        }
    }
    buffer[size] = '\0';
}

int main(int argc, char *argv[]) {

    int sockfd, newsockfd, port, n;
    socklen_t client_len;
    char buffer[256];
    sockaddr_in serv_addr, client_addr;

    if (argc < 2) {
        std::cerr << "Failed, no port provided!" << std::endl;
        exit(-1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *)&serv_addr, sizeof(serv_addr));
    port = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Failed, can't bind!");

    listen(sockfd, 5);
    client_len = sizeof(client_addr);

    while ((newsockfd =
                accept(sockfd, (sockaddr *)&client_addr, &client_len)) >= 0) {
        if (newsockfd < 0)
            error("Failed, can't accept");

        while (true) {
            bzero(buffer, 256);
            n = read(newsockfd, buffer, 254);
            std::string message(buffer);

            if (n < 0)
                error("Failed, can't read socket!");
            if (memcmp(buffer, "Bye", strlen("Bye")) == 0) {
                write(newsockfd, "Closing connection, see you nex time:(", 38);
                break;
            }
            printf("Here is a message %s", buffer);
            n = write(newsockfd, (char *)&message[0], message.size());
            if (n < 0)
                error("ERROR writing to socket");
        }
        close(newsockfd);
    }

    close(sockfd);
    return 0;
}
