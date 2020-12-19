#include "client.h"
#include <memory>
/**
 * The server doesn't respond immediatly, what should we do in the mean time?
 * A QEventLoop can be used to wait in a loop until the server responds.
 *
 * @brief blockUntilReplyReceived Don't return until reply is received by server.
 * @param reply The object to wait on.
 */
void Client::blockUntilReplyReceived(QNetworkReply* reply) {
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
}

/**
 * The server replies with a JSON object, to be useful, we want to map that JSON
 * object into a C++ object.
 *
 * @brief parseJson Convert the JSON object into a C++ object.
 * @param reply The reply received from the server.
 * @return A unique_ptr to a ForumPost object.
 */
unique_ptr<ForumPost> Client::parseJson(QNetworkReply& reply) {
    QString strReply = (QString) reply.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject jsonObject = doc.object();

    int userId = jsonObject.value("userId").toInt();
    int id = jsonObject.value("id").toInt();
    string title = jsonObject.value("title").toString().toStdString();
    string body = jsonObject.value("body").toString().toStdString();
    unique_ptr<ForumPost> post = make_unique<ForumPost>(userId, id, title, body);
    return post;
}

Client::Client(QObject *parent) {
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(onResult(QNetworkReply*)));
}

Client::~Client() {
    delete networkManager;
}

/**
 * @brief request Request something from the server.
 * @param postId The postId we are requesting from the server.
 * @return A unique_ptr to a ForumPost object.
 */
unique_ptr<ForumPost> Client::request(int commentId) {
    QNetworkRequest request;
    QNetworkReply* reply;

   request.setUrl(QUrl("http://jsonplaceholder.typicode.com/comments/"
                        + QString::number(commentId)));
    reply = networkManager->get(request);
    blockUntilReplyReceived(reply);

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->errorString();
        return nullptr;
    }
    return parseJson(*reply);

}
