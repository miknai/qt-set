#include <QPixmap>
#include <QPainter>
#include <QDataWidgetMapper>
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

    // TODO: find a way to parameterize them
    connect(ui->label, SIGNAL(clicked()), signalMapper, SLOT(map()));
    connect(ui->label_2, SIGNAL(clicked()), signalMapper, SLOT(map()));
    //connect(ui->label_3, SIGNAL(clicked()), signalMapper, SLOT(map()));

    signalMapper->setMapping(ui->label, 0);
    signalMapper->setMapping(ui->label_2, 1);
    //signalMapper->setMapping(ui->label_3, 2);


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

    cardsOnTable[0].pixOn.load("/Users/geonsookim/Desktop/qt-set/img/card1.png");
    cardsOnTable[1].pixOn.load("/Users/geonsookim/Desktop/qt-set/img/card2.png");
    cardsOnTable[2].pixOn.load("/Users/geonsookim/Desktop/qt-set/img/card3.png");

    QRectF rect(0, 0, cardsOnTable[0].pix.width()-1, cardsOnTable[0].pix.height()-1);
    QPen pen("red");
    pen.setWidth(3);

    QPainter painter;

    painter.begin(&cardsOnTable[0].pixOn);
    painter.setPen(pen);
    painter.drawRoundedRect(rect, 20, 20);
    painter.end();

    painter.begin(&cardsOnTable[1].pixOn);
    painter.setPen(pen);
    painter.drawRoundedRect(rect, 20, 20);
    painter.end();

    painter.begin(&cardsOnTable[2].pixOn);
    painter.setPen(pen);
    painter.drawRoundedRect(rect, 20, 20);
    painter.end();

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
//    QPixmap temp;
//    if(!cardsOnTable[labelNum].selected) {
//        temp = cardsOnTable[labelNum].pix;
//        ui->label_3->setPixmap(temp);
//    }

    cardsOnTable[labelNum].selected = !cardsOnTable[labelNum].selected;

    QString str1 = QString("pressed%1").arg(labelNum);
    QString str2 = QString("toggled%1").arg(labelNum);

//    ui->label->setPixmap(cardsOnTable[labelNum].pix);
//    ui->label->setPixmap(cardsOnTable[labelNum].pix);
//    ui->label->setPixmap(cardsOnTable[labelNum].pix);

//    QDataWidgetMapper *mapper = new QDataWidgetMapper;
//    //mapper->setModel(myModel);
//    mapper->addMapping(ui->label, 0);
//    mapper->addMapping(ui->label_2, 1);
//    mapper->addMapping(ui->label_3, 2);

//    QPixmap *temp = new QPixmap;
//    temp = &cardsOnTable[labelNum].pix;
//    QPixmap temp2 = *temp;

//    QRectF rect(0, 0, cardsOnTable[labelNum].pix.width()-1, cardsOnTable[labelNum].pix.height()-1);
//    QPen pen("red");
//    pen.setWidth(3);

    //QPixmap temp;
//    QPainter painter;
//    painter.begin(&cardsOnTable[labelNum].pix);
//    painter.save();
//    painter.end();
    if(cardsOnTable[labelNum].selected) {
        ui->mousePressChecker->setText(str1);
//        painter.begin(&cardsOnTable[labelNum].pix);
//        //painter.save();
//        painter.setPen(pen);
//        painter.drawRoundedRect(rect, 20, 20);
//        painter.end();
        //ui->label->setPixmap(cardsOnTable[labelNum].pix);
        ui->label->setPixmap(cardsOnTable[labelNum].pixOn);

    } else {
        ui->mousePressChecker->setText(str2);
//        painter.begin(&cardsOnTable[labelNum].pix);
//        painter.setPen(Qt::NoPen);
//        painter.drawRoundedRect(rect, 20, 20);

//        painter.restore();
//        painter.end();

//        ui->label->setPixmap(temp);
//        ui->label->setPixmap(cardsOnTable[1].pix);
        ui->label->setPixmap(cardsOnTable[labelNum].pix);

    }






//    QPainter painter;
//    painter.begin(&pix1);
//    painter.setPen(pen);
//    painter.drawRoundedRect(rect, 20, 20);
//    painter.end();
//    ui->label->setPixmap(pix1);
}
