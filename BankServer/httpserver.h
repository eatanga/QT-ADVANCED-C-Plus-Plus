#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <iostream>
#include <sstream>
#include <QCoreApplication>
#include <QDir>
#include <sstream>
#include <httplib.h>
#include <bank.h>
using namespace std;
using namespace httplib;

class HttpServer {
private:
    char* domain = "localhost";
    int port = 8080;
public:
    void startServer(Bank bank) {
        Server svr;

        svr.Get("/", [this](const Request&, Response& res) {
            stringstream body;
            body << "<html><h1>Welcome to 1/64 Bank</h1>";
            body << "To view an account balance visit http://localhost:" << this->port;
            body << "/accounts/x where x is the account number.</p></html>";
            res.set_content(body.str(), "text/html");
        });

        svr.Get(R"(/accounts/(\d+))", [&](const Request& req, Response& res) {
            Database database;
            database.open();

            int accountId = stoi(string(req.matches[1]));

            stringstream body;
            body << "<html><h1> Account "<< accountId<< "</h1>";

            /* TODO: Respond with a message containing the account id and balance.
             * hint: Use bank.getDatabase().getAccount(accountId, account)
             * You will first need to create an Account object to pass
             * into getAccount(), the account will be set with values from
             * the database.
             */
            Account acc(accountId);
            bank.getDatabase().getAccount(accountId, acc);
             body <<"<p>Balance $"<<acc.getBalance() <<"</p>";
            body << "</html>";
            res.set_content(body.str(), "text/html");
            database.close();
        });

        cout << "Starting server at http://" << domain << ":" << port << endl;
        svr.listen(domain, port);
    }
};

#endif // HTTPSERVER_H
