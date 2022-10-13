#include "Request.h"

class WebServer {
    private:
    char webServerID;
    int probability;


    public:
    WebServer (char ID);

    Request* getRequest ();

    bool roll ();

    void print ();
};