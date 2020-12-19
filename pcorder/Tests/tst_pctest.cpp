#include <QtTest>
#include "desktop.h"
#include "laptop.h"
#include "CPU.h"
#include "Memory.h"
#include "Storage.h"
#include "PowerSupply.h"
#include "Screen.h"
#include "Battery.h"

// add necessary includes here

class pctest : public QObject
{
    Q_OBJECT

public:
    pctest();
    ~pctest();

private slots:
    void test_desktotal();
    void test_laptotal();
    void test_deskout();
    void test_lapout();

};

pctest::pctest()
{

}

pctest::~pctest()
{

}

//Test total price output for desktop
void pctest::test_desktotal()
{
    CPU c;
    Memory m;
    Storage s;
    PowerSupply p;
    c.setPrice(300);
    m.setPrice(200);
    s.setPrice(100);
    p.setPrice(50);

    Desktop d(c,m,s,p);
    QCOMPARE(d.totalPrice(),650);
}

//Test total price output for laptop
void pctest :: test_laptotal()
{
    CPU c;
    Memory m;
    Storage s;
    Screen sc;
    Battery b;

    c.setPrice(300);
    m.setPrice(200);
    s.setPrice(100);
    sc.setPrice(50);
    b.setPrice(25);

    Laptop l(c,m,s,sc,b);
    QCOMPARE(l.totalPrice(),675);
}
void pctest :: test_deskout()
{
    CPU c;
    Memory m;
    Storage s;
    PowerSupply p;
    c.setName("Intel i9");
    c.setSpeed("2.8GHZ");
    c.setNumOfCores(9);
    c.setPrice(2500);
    m.setClockSpeed("2133MHZ");
    m.setSize("8GB");
    m.setPrice(100);
    s.setSize("0.128TB");
    s.setPrice(100);
    p.setRating("300W");
    p.setPrice(250);
 //test mutators to ensure they retutn the right object
    QVERIFY(c.getName()=="Intel i9");
    QVERIFY(m.getCLockSpeed()=="2133MHZ");
    QVERIFY(s.getSize()=="0.128TB");
    QVERIFY(p.getRatings()=="300W");
}
void pctest :: test_lapout()
{
    CPU c;
    Memory m;
    Storage s;
    Screen sc;
    Battery b;

    c.setName("Intel i9");
    c.setSpeed("2.8GHZ");
    c.setNumOfCores(9);
    c.setPrice(2500);
    m.setClockSpeed("2133MHZ");
    m.setSize("8GB");
    m.setPrice(100);
    s.setSize("0.128TB");
    s.setPrice(100);
    sc.setSize("23 inches");
    sc.setPrice(500);
    b.setCapacity("3HRS");
    b.setPrice(150);

    //test mutators to ensure they retutn the right object
    QVERIFY(c.getName()=="Intel i9");
    QVERIFY(m.getCLockSpeed()=="2133MHZ");
    QVERIFY(s.getSize()=="0.128TB");
    QVERIFY(sc.getSize()=="23 inches");
    QVERIFY(b.getCapacity()=="3HRS");

}
QTEST_APPLESS_MAIN(pctest)

#include "tst_pctest.moc"
