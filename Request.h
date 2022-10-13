#include <string>
using namespace std;

class Request {
    private:

        char webServerID;
        string inIP;
        string outIP;
        int timeLeft;

        string getIP (); 

    public:

        Request ();

        Request (char ID);

        string getInIP ();

        string getOutIP ();

        char getWebServerID ();

        int getTimeLeft ();

        void tick ();

        void printStatus ();
};