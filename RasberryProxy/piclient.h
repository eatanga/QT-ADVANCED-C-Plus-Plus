#ifndef PICLIENT_H
#define PICLIENT_H

#include <QObject>
#include <iostream>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
using namespace std;

class PiClient : public QObject
{
    Q_OBJECT

public:
    explicit PiClient(QObject *parent = nullptr);
    void clientConnect();
    string read();
    void send(string command);
signals:

public slots:
    void connected();
    void disconnected();
    void bytesWritten (qint64 bytes);
    void readyRead();
    void checkNewCommand();
private:
    QTcpSocket *socket;
    string response;
    string command;
};

#endif // PICLIENT_H
