#include <QPixmap>
#include <QPainter>
//#include <QThread>
#include <QDebug>
#include <QSignalMapper>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sleeper.h"
#include "set.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSignalMapper* signalMapper = new QSignalMapper(this);
    connect(ui->label, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->label_2, SIGNAL(clicked()), signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->label, 1);
    signalMapper->setMapping(ui->label_2, 2);

//    connect(ui->label, SIGNAL(clicked()), this, SLOT(MousePressed(1)));
//    connect(ui->label_2, SIGNAL(clicked()), this, SLOT(MousePressed2(2)));
    //connect(ui->label_3, SIGNAL(clicked()), this, SLOT(MousePressed()));

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(MousePressed(int)));


    QVector<Set::Card> cards(Set::totalCardNum+1);
    QVector<Set::Card> cardsOnTable;

    // initalize card deck
    Set::initialize(cards);
//    qInfo() << "initialize";
//    Set::print(cards);

    // shuffle card deck
    Set::shuffle(cards);
//    qInfo() << "shuffle";
//    Set::print(cards);

    // put 12 cards on table
    Set::putOnTable(cards, cardsOnTable);
//    qInfo() << "cardsOnTable";
//    Set::print(cardsOnTable);

    cardsOnTable[0].pix.load("/Users/geonsookim/Desktop/qt-set/img/card1.png");
    cardsOnTable[1].pix.load("/Users/geonsookim/Desktop/qt-set/img/card2.png");
    cardsOnTable[2].pix.load("/Users/geonsookim/Desktop/qt-set/img/card3.png");

    ui->label->setPixmap(cardsOnTable[0].pix);
    ui->label_2->setPixmap(cardsOnTable[1].pix);
    ui->label_3->setPixmap(cardsOnTable[2].pix);




//    pix1.load("/Users/geonsookim/Desktop/qt-set/img/card1.png");
//    ui->label->setPixmap(pix1);

    //Sleeper::sleep(3);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MousePressed(int labelNum)
{
    if(labelNum == 1) {
        state = !state;
        if(state) {
            ui->mousePressChecker->setText("pressed");
        } else {
            ui->mousePressChecker->setText("toggle");
        }
    }

    if(labelNum == 2) {
        state2 = !state2;
        if(state2) {
            ui->mousePressChecker->setText("pressed2");
        } else {
            ui->mousePressChecker->setText("toggle2");
        }
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

//void MainWindow::MousePressed2()
//{
//    state2 = !state2;
//    if(state2) {
//        ui->mousePressChecker->setText("pressed2");
//    } else {
//        ui->mousePressChecker->setText("toggle2");
//    }
//}


