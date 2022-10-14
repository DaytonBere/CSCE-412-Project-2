#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <queue>

#include "LoadBalancer.h"


/*! \mainpage CSCE-412 Project 2 Dayton Berezoski (228005087)
 *
 * This is the Doxygen webpage for my CSCE 412 Project 2.
 * GitHub link: https://github.com/DaytonBere/CSCE-412-Project-2
 *
 */

int main() {
    srand(time(0));
    std::cout << "Welcome to CSCE 412 project 2 Load Balancer by Dayton Berezoski" << std::endl << std::endl;


    int MAXWEBSERVERS ;
    std::cout << "Please type the number of servers to create here (max is 26): ";
    std::cin >> MAXWEBSERVERS;
    std::cout << std::endl << std::endl;
    
    int MAXQUEUE;
    std::cout << "Please type the max size of the queue (-1 to default to 2*Max Web Servers): ";
    std::cin >> MAXQUEUE;
    if (MAXQUEUE == -1) {
        MAXQUEUE = 2 * MAXWEBSERVERS;
    }
    std::cout << std::endl << std::endl;

    long long MAXTIME;
    std::cout << "Please type the number of ticks to run the server for: ";
    std::cin >> MAXTIME;
    std::cout << std::endl << std::endl;

    LoadBalancer* load = new LoadBalancer(MAXWEBSERVERS, MAXQUEUE, MAXTIME);
    load->run();
}