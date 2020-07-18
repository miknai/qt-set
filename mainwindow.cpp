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
    childs = ui->gridLayoutWidget->findChildren<ClickableLabel*>();
    for (int i = 0; i < childs.size(); ++i) {
        connect(childs[i], SIGNAL(clicked()), signalMapper, SLOT(map()));
        signalMapper->setMapping(childs[i], i);
    }
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(MousePressed(int)));

    QVector<Set::Card> deck(Set::totalCardNum+1);
    cards.append(deck);
    // initalize card deck
    Set::initialize(cards);
//    qInfo() << "initialize";
//    Set::print(cards);

    // shuffle card deck
    Set::shuffle(cards);
//    qInfo() << "shuffle";
//    Set::print(cards);

    // put 12 cards on table
    Set::setInitialCards(cards, cardsOnTable);
//    qInfo() << "cardsOnTable";
//    Set::print(cardsOnTable);

    Set::loadPix(cardsOnTable);
    Set::paintPixOn(cardsOnTable);

    for (int i = 0; i < childs.size(); ++i) {
        childs[i]->setPixmap(cardsOnTable[i].pixOff);
    }
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

    bool validSet = false;
    if(cardsOnTable[labelNum].selected) {
        clickedIndex.push_back(labelNum);
        childs[labelNum]->setPixmap(cardsOnTable[labelNum].pixOn);

        int clickedNum = clickedIndex.size();
        if(clickedNum >= 3) {
            validSet = Set::isSet(cardsOnTable, clickedIndex);
            for(int i=0; i < clickedNum; ++i) {
                childs[clickedIndex.front()]->setPixmap(cardsOnTable[clickedIndex.front()].pixOff);
                cardsOnTable[clickedIndex.front()].selected = false;
                clickedIndex.pop_front();
            }
        }

        ui->mousePressChecker->setText(str1);
        //childs[labelNum]->setPixmap(cardsOnTable[labelNum].pixOn);
        if(validSet) {ui->mousePressChecker->setText("SET");}
        //else { ui->mousePressChecker->setText("not SET");}
    } else {
        if(clickedIndex.contains(labelNum)) {
            clickedIndex.remove(clickedIndex.indexOf(labelNum));
        }
        ui->mousePressChecker->setText(str2);
        childs[labelNum]->setPixmap(cardsOnTable[labelNum].pixOff);

    }
    ui->clickedCardNum->setText(QString::number(clickedIndex.size()));

//    qInfo() << "buffer";
//    for(int i : clickedIndex) {
//        qInfo() << i << " ";
//    }
}
