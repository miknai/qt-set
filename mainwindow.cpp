#include <QPixmap>
#include <QPainter>
#include <QThread>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sleeper.h"
//#include "myqpixmap.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->label, SIGNAL(MousePressed()), this, SLOT(MousePressed()));

    QPixmap pix1("/Users/geonsookim/Desktop/qt-set/img/card1.png");
    ui->label->setPixmap(pix1);

    //Sleeper::sleep(3);

//    QRectF rect(0, 0, pix1.width()-1, pix1.height()-1);
//    QPen pen("red");
//    pen.setWidth(3);
//    QPainter painter;
//    painter.begin(&pix1);
//    painter.setPen(pen);
//    painter.drawRoundedRect(rect, 20, 20);
//    painter.end();
//    ui->label->setPixmap(pix1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::mousePressEvent(QMouseEvent *ev)
//{
//    emit MousePressed();
//}

void MainWindow::MousePressed()
{
    ui->mousePressChecker->setText("Mouse Pressed");
}

