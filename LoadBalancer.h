#include <string>
#include <queue>
#include "WebServer.h"

/*!
 * @file LoadBalancer.h 
 * @brief The LoadBalancer class takes in the appropriate parameters and simulates a load balancer working on random requests generated randomly by the web servers.
 * 
 * This class uses the Request and WebServer classes inside of it to run the simulation.
 */

class LoadBalancer {
    private:
        /*! This is the queue that all of the in progress Requests sit in */
        std::queue<Request*> processQueue; 

        /*! This queue stores requests while the processQueue is full*/
        std::queue<Request*> awaitQueue; 

        /*! This queue holds already processed Requests for one tick to be put back into the processQueue */
        std::queue<Request*> tempQueue; 

        /*! This allows access to all of the generated WebServers */
        std::vector<WebServer*> servers; 

        /*! Max number of WebServers to be generated */
        int MAXWEBSERVERS; 

        /*! Max number of Requests that can be in the processQueue at one time */
        int MAXQUEUE; 

        /*! How long the load balancer will run for */
        long long MAXTIME; 

        /*! Tracks how many Requests have been completed */
        int requestsCompleted; 
    
    public:
        /*! Constructor that takes in user input in main(). Web chooses how many WebServers to create. Queue sets the max number of Requests to hold in the processQueue. Time sets the number of ticks to run for.
        */
        LoadBalancer (int web, int queue, long long time); 

        /*! Counts down one tick for every Request in the processQueue and adds the remaining ones to teh tempQueue */
        void processRequests (int i); 

        /*! For every WebServer, potentially generate a new Request to the awaitQueue */
        void generateRequests (); 

        /*! Move the Requests back into the processQueue from the tempQueue, flush the tempQueue, and add Requests from the awaitQueue if there are slots open */
        void refillRequests ();

        /*! Uses processRequests(i), generateRequests (), and refillRequests () to start simulation, prints appropriate data */
        void run (); 
};
        