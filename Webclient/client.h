#ifndef CLIENT_H
#define CLIENT_H


#include<QApplication>
#include<QObject>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QDebug>
#include<QJsonObject>
#include<QJsonDocument>
#include<iostream>
#include <memory>

using namespace std;

struct ForumPost {
    int userId;
    int id;
    string title;
    string body;
};

class Client: QObject {
Q_OBJECT
private:
    QNetworkAccessManager* networkManager;
    void blockUntilReplyReceived(QNetworkReply* reply);
    unique_ptr<ForumPost> parseJson(QNetworkReply& reply);
public:
    explicit Client(QObject *parent = nullptr);
    ~Client();
    unique_ptr<ForumPost> request(int postId);
signals:
public slots:
    void onResult(QNetworkReply *reply) { }
};

#endif // CLIENT_H
