#include <string>

class Request {
    private:

        char webServerID;
        std::string inIP;
        std::string outIP;
        int timeLeft;

        std::string getIP (); 

    public:

        Request ();

        Request (char ID);

        std::string getInIP ();

        std::string getOutIP ();

        char getWebServerID ();

        int getTimeLeft ();

        void tick ();

        void printStatus ();
};