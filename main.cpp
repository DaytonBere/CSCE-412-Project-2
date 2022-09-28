#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>

class Request {
    private:

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

    Request();

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
        std::cout << "inIP: " << inIP << ", outIP: " << outIP << std::endl;
    }
};


Request::Request() {
    inIP = getIP();
    outIP = getIP();
    timeLeft = rand() % 100 + 1;
}



int main() {
    srand(time(0));
    std::queue<Request*> q;
    Request *test = new Request();
    q.push(test);

    for (int i; i < 1000; i++){
        if (q.size() > 0) {
            if (q.front()->getTimeLeft() <= 0) {
                std::cout << "Time: " << i << " ";
                q.front()->printStatus();
                q.pop();
            } else {
                q.front()->tick();
            }
        }

        if (rand() % 20 == 0) {
            Request *nReq = new Request();
            q.push(nReq);
        }
    }

    std::cout << "Ended with " << q.size() << " items in the queue" << std::endl;
}