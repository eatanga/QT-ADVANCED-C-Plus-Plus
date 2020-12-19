#include <QtTest>
#include "desktop.h"
#include "laptop.h"

// add necessary includes here

class pctests : public QObject
{
    Q_OBJECT

public:
    pctests();
    ~pctests();

private slots:
    void test_case1();

};

pctests::pctests()
{

}

pctests::~pctests()
{

}

void pctests::test_case1()
{

}

QTEST_APPLESS_MAIN(pctests)

#include "tst_pctests.moc"
