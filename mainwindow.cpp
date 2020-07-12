#include <QPixmap>
#include <QPainter>
//#include <QThread>
#include <QDebug>
#include <QSignalMapper>
#include <QString>

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

    signalMapper->setMapping(ui->label, 0);
    signalMapper->setMapping(ui->label_2, 1);

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(MousePressed(int)));


    QVector<Set::Card> cards(Set::totalCardNum+1);

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MousePressed(int labelNum)
{
    cardsOnTable[labelNum].selected = !cardsOnTable[labelNum].selected;

    QString str1 = QString("pressed%1").arg(labelNum);
    QString str2 = QString("toggled%1").arg(labelNum);

    QRectF rect(0, 0, cardsOnTable[labelNum].pix.width()-1, cardsOnTable[labelNum].pix.height()-1);
    QPen pen("red");
    pen.setWidth(3);

    if(cardsOnTable[labelNum].selected) {
        ui->mousePressChecker->setText(str1);
        QPainter painter;
        painter.begin(&cardsOnTable[labelNum].pix);
        painter.setPen(pen);
        painter.drawRoundedRect(rect, 20, 20);
        painter.end();
//        ui->label->setPixmap(cardsOnTable[labelNum].pix);
        ui->label->setPixmap(cardsOnTable[labelNum].pix);

    } else {
        ui->mousePressChecker->setText(str2);
    }






//    QPainter painter;
//    painter.begin(&pix1);
//    painter.setPen(pen);
//    painter.drawRoundedRect(rect, 20, 20);
//    painter.end();
//    ui->label->setPixmap(pix1);
}
