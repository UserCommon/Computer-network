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

Message::Message(char arg[25], double w, double h) {
    memcpy(name, arg, 25);
    weight = w;
    height = h;
}

Message::Message() {
    char empty_arr[25];
    memcpy(name, empty_arr, 25);
}

double Message::getBMI() { return weight / ((height / 100) * (height / 100)); }

char *Message::getBMIResult() {
    char *res = new char[25];
    std::cout << getBMI() << std::endl;
    if ((getBMI() >= 18.5) && (getBMI() <= 24.9))
        res = "normal";
    if (getBMI() > 24.9)
        res = "overweight";
    if (getBMI() < 18.5)
        res = "undernourished";
    return res;
}

void Message::setName(char arg[25]) { memcpy(name, arg, 25); }
void Message::setWeight(double w) { weight = w; }
void Message::setHeight(double h) { height = h; }

std::string Message::getName() { return std::string(name); }
double Message::getWeight() { return weight; }
double Message::getHeight() { return height; }
