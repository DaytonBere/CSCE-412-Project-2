#include <iostream>
#include <queue>

#include "LoadBalancer.h"

LoadBalancer::LoadBalancer (int web, int queue, long long time) {
    MAXWEBSERVERS = web;
    MAXQUEUE = queue;
    MAXTIME = time;
    reqestsCompleted = 0;

    char LETTER = 'A';
    for (int i = 0; i < MAXWEBSERVERS; i++) {
        WebServer *nWebServer = new WebServer(LETTER);
        servers.push_back(nWebServer);
        LETTER++;
    }
}

void LoadBalancer::processRequests (int i) {
    while (processQueue.size() > 0) {
        if (processQueue.front()->getTimeLeft() <= 0) {
            if (processQueue.front()->getWebServerID() != '-') {
                std::cout << "Time: " << i << ", ";
                processQueue.front()->printStatus();
                reqestsCompleted++;
            }
            processQueue.pop();
        } else {
            processQueue.front()->tick();
            tempQueue.push(processQueue.front());
            processQueue.pop();
        }
    }
}

void LoadBalancer::generateRequests () {
    for (int i = 0; i < servers.size(); i++) {
        if (servers[i]->roll()) {
            Request *nReq = servers[i]->getRequest();
            awaitQueue.push(nReq);
        }
    }
}

void  LoadBalancer::refillRequests () {
    processQueue = tempQueue;

    while (processQueue.size() < MAXQUEUE && awaitQueue.size() > 0) {
        processQueue.push(awaitQueue.front());
        awaitQueue.pop();
    }

    std::queue<Request*> empty;
    tempQueue = empty;
}

void LoadBalancer::run () {
    for (int i = 0; i < MAXTIME; i++) {
        processRequests (i);
        generateRequests ();
        refillRequests ();
    }
    std::cout << std::endl;
    std::cout << reqestsCompleted << " requests completed" << std::endl;
    std::cout << "Ended with " << processQueue.size() << " items in the process queue" << std::endl;
    std::cout << "Ended with " << awaitQueue.size() << " items in the await queue" << std::endl;
}