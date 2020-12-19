//Emmanuel Atanga
//Alternative Division Of Labor
//11/17/2020


#include <iostream>
#include <array>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QMutex>
using namespace std;

const int SIZE = 1000;

class SumThread: public QThread {
private:
    array<array<long, SIZE>, SIZE> &table;
    size_t startRow;
    size_t skipRows;
    static long total;
    static QMutex mutex;
public:
    SumThread(array<array<long, SIZE>, SIZE> &table, size_t startRow, size_t skipRows):
        table(table), startRow(startRow), skipRows(skipRows) {
        total = 0;
    }

    void run() {

        for (size_t row=startRow; row<table.size(); row+=skipRows) {
            long rowTotal = 0;
            for (size_t column=0; column<table[0].size(); column++) {
                rowTotal += table[row][column];
            }
             mutex.lock();
            total += rowTotal;
                  mutex.unlock();
        }
    }

    static long getTotal() {
        return total;

    }
};
QMutex SumThread::mutex;

long SumThread::total;
array<array<long, SIZE>, SIZE> bigTable;

int main() {
    for (size_t i=0; i<bigTable.size(); i++) {
        for (size_t j=0; j<bigTable[0].size(); j++) {
            bigTable[i][j] = static_cast<long>(i + j);
        }
    }

    for (int i=0; i<100; i++) {
        SumThread thread1(bigTable, 0, 4);
        SumThread thread2(bigTable, 1/4, 4);
        SumThread thread3(bigTable, 1/2, 4);
        SumThread thread4(bigTable, 3/4, 4);

        thread1.start();
        thread2.start();
        thread3.start();
        thread4.start();

        thread1.wait();
        thread2.wait();
        thread3.wait();
        thread4.wait();

        cout << SumThread::getTotal() << " " << endl;
    }
    return 0;
}
