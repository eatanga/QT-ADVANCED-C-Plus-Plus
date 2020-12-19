#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRegExpValidator>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->redDial->setRange(0, 255);
    ui->greenDial->setRange(0, 255);
    ui->blueDial->setRange(0, 255);

    ui->redDial->setValue(0);
    ui->greenDial->setValue(0);
    ui->blueDial->setValue(0);

    ui->redEdit->setText("0");
    ui->greenEdit->setText("0");
    ui->blueEdit->setText("0");

    QRegExpValidator* numValidater = new QRegExpValidator(QRegExp("\\d*"));
    ui->redEdit->setValidator(numValidater);
    ui->greenEdit->setValidator(numValidater);
    ui->blueEdit->setValidator(numValidater);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->colorView->setScene(scene);
    colorRectangle = scene->addRect(0, 0, ui->colorView->width(), ui->colorView->height(), QPen(Qt::black), QBrush(Qt::black));
    colorRectangle->update();


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updatePreview() {
    colorRectangle->setBrush(QBrush(QColor(ui->redDial->value(),
                                           ui->greenDial->value(),
                                           ui->blueDial->value())));
    colorRectangle->update();
}

void MainWindow::updateValues(QLineEdit* edit, QDial* dial) {
    int value = edit->text().toInt();
    if (value > 255) {
        edit->setText("255");
        value = 255;
    } else if (value < 0) {
        edit->setText("0");
        value = 0;
    }

    dial->setValue(value);
}

void MainWindow::editUpdate() {
    updateValues(ui->redEdit, ui->redDial);
    updateValues(ui->greenEdit, ui->greenDial);
    updateValues(ui->blueEdit, ui->blueDial);
    updatePreview();
}

void MainWindow::sliderUpdate() {
    ui->redEdit->setText(QString::number(ui->redDial->value()));
    ui->greenEdit->setText(QString::number(ui->greenDial->value()));
    ui->blueEdit->setText(QString::number(ui->blueDial->value()));
    updatePreview();
}


void MainWindow::buttonClicked() {
    //Only one color gets updated based on the random value generated.
    //This is because if all the colors get updated with the random value, it only give a black color

    int value = QRandomGenerator::global()->bounded(0,255);
    if (value < 100) {
     ui->redDial->setValue(value);
     ui->redEdit->setText(QString::number(value));
    } else if (value > 100 && value < 200) {
    ui->greenDial->setValue(value);
     ui->greenEdit->setText(QString::number(value));
    }else if (value > 200 && value < 255) {
       ui->blueDial->setValue(value);
       ui->blueEdit->setText(QString::number(value));
        }

}

