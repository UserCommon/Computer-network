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

#include "Message.hpp"

Message::Message() {
    char *empty_buf = new char[1024];
    for (int i = 0; i < 1024; ++i) {
        empty_buf[i] = 0;
    }
    memcpy(m_message, empty_buf, 1024);
}

Message::Message(char array[1024]) { memcpy(m_message, array, 1024); }

std::string Message::msgAsString() { return std::string(m_message); }
