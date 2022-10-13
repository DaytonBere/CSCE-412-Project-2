#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "WebServer.h"

WebServer::WebServer (char ID) {
    webServerID = ID;
    probability = rand() % 80 + 20;
}

Request* WebServer::getRequest () {
    return new Request(webServerID);
}

bool WebServer::roll () {
    int r = rand() % probability;
    return r == 0;
}

void WebServer::print () {
    std::cout << "WebServerID: " << webServerID << ", Probability: " << probability << std::endl;
}
