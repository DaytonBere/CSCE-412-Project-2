#include "Request.h"

/*!
 * @file WebServer.h 
 * @brief The WebServer class will create randomly Requests with their ID matching the WebServer.
 * 
 * This class has an associated probability that is also randomly generated to determine the probability of generating a Request.
 */
class WebServer {
    private:

    
    char webServerID; /*! Alphabetic character used to id the Request generated by this WebServer */

    /*! Probability that a new Request will be generated every tick */
    int probability;

    public:

    /*! Constructor that requires an ID for the webServerID value */
    WebServer (char ID);

    /*! Generates a Request with the same ID as the webServerID */
    Request* getRequest ();

    /*! 1 in probability chance to return True */
    bool roll ();

    /*! Prints data about the WebServer */
    void print ();
};