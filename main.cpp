#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

class Request {
    private:

    char webServerID;
    string inIP;
    string outIP;
    int timeLeft;

    string getIP () {

        int one = rand() % 256;
        int two = rand() % 256;
        int three = rand() % 256;
        int four = rand() % 256;

        string IP = to_string(one) + "." + to_string(two) + "." + to_string(three) + "." + to_string(four);
        return IP;
    }

    public:

    Request (char ID) {
        webServerID = ID;
        inIP = getIP();
        outIP = getIP();
        timeLeft = rand() % 100 + 1;
    }

    Request () {
        webServerID = '-';
        inIP = getIP();
        outIP = getIP();
        timeLeft = 0;
    }

    string getInIP () {
        return inIP;
    }
    string getOutIP () {
        return outIP;
    }

    char getWebServerID () {
        return webServerID;
    }

    int getTimeLeft () {
        return timeLeft;
    }

    void tick () {
        timeLeft--;
    }

    void printStatus () {
        cout << " Web Server: " <<  webServerID <<  ", inIP: " << inIP << ", outIP: " << outIP << endl;
    }
};

class WebServer {
    private:
    char webServerID;
    int probability;


    public:
    WebServer (char ID) {
        webServerID = ID;
        probability = rand() % 10 + 10;
    }

    Request* getRequest () {
        return new Request(webServerID);
    }

    bool roll () {
        int r = rand() % probability;
        return r == 0;
    }

    void print () {
        cout << "WebServerID: " << webServerID << ", Probability: " << probability << endl;
    }
};






int main() {
    srand(time(0));

    char LETTER = 'A';
    int MAXQUEUE = 5;
    int MAXWEBSERVERS = 7;


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


    for (int i = 0; i < 1000; i++) {
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