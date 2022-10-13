#include <string>
#include <queue>
#include "WebServer.h"


class LoadBalancer {
    private:
        std::queue<Request*> processQueue;
        std::queue<Request*> awaitQueue;
        std::queue<Request*> tempQueue;
        std::vector<WebServer*> servers;
        int MAXWEBSERVERS;
        int MAXQUEUE;
        long long MAXTIME;
        int reqestsCompleted;
    
    public:
        LoadBalancer (int web, int queue, long long time);
        void processRequests (int i);
        void generateRequests ();
        void refillRequests ();
        void run ();
       
};