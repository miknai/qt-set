#include <QPixmap>
#include <QPainter>
//#include <QThread>
#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sleeper.h"
#include "set.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->label, SIGNAL(clicked()), this, SLOT(MousePressed()));

    QVector<Set::Card> cards(Set::totalCardNum+1);

    // initalize card deck
    Set::initialize(cards);
    //qInfo() << "initialize";
    //Set::print(cards);

    // shuffle card deck
    Set::shuffle(cards);
    //qInfo() << "shuffle";
    //Set::print(cards);

    // pick 12 cards and put on table



//    pix1.load("/Users/geonsookim/Desktop/qt-set/img/card1.png");
//    ui->label->setPixmap(pix1);

    //Sleeper::sleep(3);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MousePressed()
{
    state = !state;
    if(state) {
        ui->mousePressChecker->setText("pressed");
    } else {
        ui->mousePressChecker->setText("toggle");
    }

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


