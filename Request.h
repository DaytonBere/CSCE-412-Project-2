#include <string>


/*!
 * @file Request.h 
 * @brief The Request class simulates the requests of random requirements being sent to the LoadBalancer.
 * 
 * This class does this by generating a in and out IP address, time to complete, and keeps track of the WebServer that created it using webServerID.
 */
class Request {
    private:
        /*! Alphabetic character the WebServer identifies the Request with during creation */
        char webServerID;

        /*! Static incoming IP address */
        std::string inIP;

        /*! Static outgoing IP address*/
        std::string outIP;

        /*! How many ticks until the Request is completed*/
        int timeLeft;

        

    public:

        /*! Default constructor needed for starting the LoadBalancer */
        Request ();

        /*! Constructor used by WebServer to identify the Request with its WebServer */
        Request (char ID);

        /*! Generates random IP address */
        std::string getIP (); 

        /*! Getter method for inIP */
        std::string getInIP ();

        /*! Getter method for outIP */
        std::string getOutIP ();

        /*! Getter method for webServerID*/
        char getWebServerID ();

        /*! Getter method for timeLeft */
        int getTimeLeft ();

        /*! Used in the LoadBalancer to reduce timeLeft by 1 */
        void tick ();

        /*! Uses getters to cout status of the Request */
        void printStatus ();
};