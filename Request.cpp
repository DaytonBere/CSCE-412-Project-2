#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Request.h"

std::string Request::getIP () {

    int one = rand() % 256;
    int two = rand() % 256;
    int three = rand() % 256;
    int four = rand() % 256;

    std::string IP = std::to_string(one) + "." + std::to_string(two) + "." + std::to_string(three) + "." + std::to_string(four);
    return IP;
}


Request::Request (char ID) {
    webServerID = ID;
    inIP = getIP();
    outIP = getIP();
    timeLeft = rand() % 100 + 1;
}

Request::Request () {
    webServerID = '-';
    inIP = getIP();
    outIP = getIP();
    timeLeft = 0;
}

std::string Request::getInIP () {
    return inIP;
}

std::string Request::getOutIP () {
    return outIP;
}

char Request::getWebServerID () {
    return webServerID;
}

int Request::getTimeLeft () {
    return timeLeft;
}

void Request::tick () {
    timeLeft--;
}

void Request::printStatus () {
    std::cout << " Web Server: " <<  webServerID <<  ", inIP: " << inIP << ", outIP: " << outIP << std::endl;
}