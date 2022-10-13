#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>

#include "WebServer.h"

using namespace std;


int main() {
    srand(time(0));
    char LETTER = 'A';
    cout << "Welcome to CSCE 412 project 2 Load Balancer by Dayton Berezoski" << endl << endl;


    int MAXWEBSERVERS ;
    cout << "Please type the number of servers to create here (max is 26): ";
    cin >> MAXWEBSERVERS;
    cout << endl << endl;
    
    int MAXQUEUE;
    cout << "Please type the max size of the queue (-1 to default to 2*Max Web Servers): ";
    cin >> MAXQUEUE;
    if (MAXQUEUE == -1) {
        MAXQUEUE = 2 * MAXWEBSERVERS;
    }
    cout << endl << endl;

    long long MAXTIME ;
    cout << "Please type the number of ticks to run the server for: ";
    cin >> MAXTIME;
    cout << endl << endl;

    queue<Request*> processQueue;
    queue<Request*> awaitQueue;

    vector<WebServer*> servers;
    for (int i = 0; i < MAXWEBSERVERS; i++) {
        WebServer *nWebServer = new WebServer(LETTER);
        servers.push_back(nWebServer);
        LETTER++;
    }

    Request *test = new Request();
    processQueue.push(test);


    for (long long i = 0; i < MAXTIME; i++) {
        queue<Request*> tempQueue;

        while (processQueue.size() > 0) {
            if (processQueue.front()->getTimeLeft() <= 0) {
                if (processQueue.front()->getWebServerID() != '-') {
                    cout << "Time: " << i << ", ";
                    processQueue.front()->printStatus();
                }
                processQueue.pop();
            } else {
                processQueue.front()->tick();
                tempQueue.push(processQueue.front());
                processQueue.pop();

            }
        }

        for (int j = 0; j < servers.size(); j++) {
            if (servers[j]->roll()) {
                Request *nReq = servers[j]->getRequest();
                awaitQueue.push(nReq);
            }
        }

        processQueue = tempQueue;

        while (processQueue.size() < MAXQUEUE && awaitQueue.size() > 0) {
            processQueue.push(awaitQueue.front());
            awaitQueue.pop();
        }
    }

    cout << endl;
    cout << "Ended with " << processQueue.size() << " items in the process queue" << endl;
    cout << "Ended with " << awaitQueue.size() << " items in the await queue" << endl;
}