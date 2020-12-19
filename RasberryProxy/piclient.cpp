#include "piclient.h"
#include "httplib.h"
#include <QTimer>
#include <QEventLoop>

using namespace httplib;
using namespace std;

PiClient::PiClient(QObject *parent): QObject(parent)
{
    response = "";
    command = "";

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&PiClient::checkNewCommand));
    timer->start(1000);
}

void PiClient::checkNewCommand()
{
    if (command != "") {
        socket->write(command.c_str());
        command = "";
    }
}

void PiClient::clientConnect()
{
    socket = new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()));
    connect(socket,SIGNAL(bytesWritten(qint64)),this,SLOT(bytesWritten(qint64)));

    qDebug()<<"connecting...";

    socket->connectToHost("telehack.com", 23);
    if(!socket->waitForConnected(1000))
    {
        qDebug() <<"Error" << socket->errorString();
    }
}

void PiClient::connected()
{
    qDebug()<<"connected!";
}

void PiClient::disconnected()
{
    qDebug()<<"Disconnected";
}

void PiClient::bytesWritten(qint64 bytes)
{
    qDebug()<<"Nuber of bytes written: " << bytes;
}

void PiClient::send(string command)
{
    this->command += command;
}

void PiClient::readyRead()
{
    qDebug() << "readyRead";
    QByteArray array = socket->readAll();
    response += array.toStdString();
    cout << response;
}

string PiClient::read()
{
    string returnString = response;
    response = "";
    return returnString;
}
