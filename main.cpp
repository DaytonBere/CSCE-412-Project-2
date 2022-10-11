#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>

class Request {
    private:

    std::string webServerID;
    std::string inIP;
    std::string outIP;
    int timeLeft;

    std::string getIP() {

        int one = rand() % 256;
        int two = rand() % 256;
        int three = rand() % 256;
        int four = rand() % 256;

        std::string IP = std::to_string(one) + "." + std::to_string(two) + "." + std::to_string(three) + "." + std::to_string(four);
        return IP;
    }

    public:

    Request(std::string ID) {
        webServerID = ID;
        inIP = getIP();
        outIP = getIP();
        timeLeft = rand() % 100 + 1;
    }

    std::string getInIP() {
        return inIP;
    }
    std::string getOutIP() {
        return outIP;
    }
    int getTimeLeft() {
        return timeLeft;
    }
    void tick() {
        timeLeft--;
    }
    void printStatus() {
        std::cout << " Web Server: " <<  webServerID <<  ", inIP: " << inIP << ", outIP: " << outIP << std::endl;
    }
};

// class WebServer {
//     private:
//     std::string webServerID;
//     int probability;


//     WebServer(std::string ID) {

//     }

// };

int main() {
    srand(time(0));

    int MAXQUEUE = 5;
    std::queue<Request*> processQueue;
    std::queue<Request*> awaitQueue;
    Request *test = new Request("D");
    processQueue.push(test);

    for (unsigned int i; i < 1000; i++){
        std::queue<Request*> tempQueue;

        while (processQueue.size() > 0) {
            if (processQueue.front()->getTimeLeft() <= 0) {
                std::cout << "Time: " << i << ", ";
                processQueue.front()->printStatus();
                processQueue.pop();
            } else {
                processQueue.front()->tick();
                tempQueue.push(processQueue.front());
                processQueue.pop();

            }
        }

        if (rand() % 10 == 0) {
            Request *nReq = new Request("A");
            awaitQueue.push(nReq);
            std::cout << std::endl << "New Request " << awaitQueue.size() << std::endl << std::endl;
        }

        processQueue = tempQueue;

        while (processQueue.size() < MAXQUEUE && awaitQueue.size() > 0) {
            processQueue.push(awaitQueue.front());
            awaitQueue.pop();
            std::cout << std::endl << "Request Pushed " << processQueue.size() << std::endl << std::endl;
        }
    }

    std::cout << "Ended with " << processQueue.size() << " items in the process queue" << std::endl;
    std::cout << "Ended with " << awaitQueue.size() << " items in the await queue" << std::endl;
}