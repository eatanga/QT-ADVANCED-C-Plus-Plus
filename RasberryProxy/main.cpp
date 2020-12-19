#include <QCoreApplication>
#include <QThread>
#include <qtconcurrentrun.h>
#include "piserver.h"
#include "piclient.h"
using namespace QtConcurrent;

class ServerThread : public QThread
{
private:
    PiClient &client;
public:
    ServerThread(PiClient &client) : client(client) { }
    void run()
    {
        PiServer p;
        p.startServer(client);
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    PiClient client;
    client.clientConnect();

    ServerThread server(client);
    server.start();

    return a.exec();
}
