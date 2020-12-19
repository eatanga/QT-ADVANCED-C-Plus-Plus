#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QDial>
#include <QGraphicsRectItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow: public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void editUpdate();
    void sliderUpdate();
    void buttonClicked();
private:
    Ui::MainWindow *ui;
    void updateValues(QLineEdit* edit, QDial* dial);
    QGraphicsRectItem *colorRectangle;
    void updatePreview();
};
#endif // MAINWINDOW_H
