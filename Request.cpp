#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Request.h"

string Request::getIP () {

    int one = rand() % 256;
    int two = rand() % 256;
    int three = rand() % 256;
    int four = rand() % 256;

    string IP = to_string(one) + "." + to_string(two) + "." + to_string(three) + "." + to_string(four);
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

string Request::getInIP () {
    return inIP;
}

string Request::getOutIP () {
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
    cout << " Web Server: " <<  webServerID <<  ", inIP: " << inIP << ", outIP: " << outIP << endl;
}