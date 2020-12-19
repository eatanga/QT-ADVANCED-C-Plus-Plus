#include "mainwindow.h"
#include "client.h"
#include <QApplication>
#include <memory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Client client;

       int postId;
       cout << "What is the id of the forum post post to you want to view (-1 to quit)? ";
       cin >> postId;
       while (postId != -1) {
           unique_ptr<ForumPost> post = client.request(postId);
           cout << post->title << endl << post->body << endl;
           cout << endl << "What is the id of the forum post post to you want to view (-1 to quit)? ";
           cin >> postId;
       }

       return a.exec();
}
