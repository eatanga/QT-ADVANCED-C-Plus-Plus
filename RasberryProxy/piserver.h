#ifndef PISERVER_H
#define PISERVER_H

#include <unistd.h>
#include <QCoreApplication>
#include <httplib.h>
#include <QDebug>
#include "piclient.h"
using namespace std;
using namespace httplib;

class PiServer {
private:
    char* domain = "localhost";
    int port = 8080;
public:
    void startServer(PiClient &client) {
        Server svr;

        // Mount / to location of index.html
        auto ret = svr.set_mount_point("/", "../RasberryProxy");
        if (!ret) {
            qDebug() << "ERROR: index.html not found.";
        }

        string commandResponse = "";

        svr.Get("/index.html", [&](const Request &, Response &res) {
            res.set_content("<html>Welcome to index.html</html>", "text/html");
        });

        svr.Post("/command", [&](const Request &req, Response &res) {
            string command = req.body;
            client.send(command);
            commandResponse = command; // echo back the command, no real response yet
            res.set_content("Your command is " + command, "text/plain");
        });

        svr.Get("/checkforupdates", [&](const Request &req, Response &res) {
            commandResponse = client.read();
            cout << "sending commandResponse" << commandResponse << endl;
            res.set_content(commandResponse, "text/plain");
        });

        qDebug() << "Starting server at http://" << domain << ":" << port;
        qDebug() << "Server listening...";
        svr.listen(domain, port);
      }
};

#endif // PISERVER_H
