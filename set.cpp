#include "set.h"
#include "assert.h"
#include <QVector>
#include <QDebug>
#include <QPainter>
#include <algorithm>


Set::Set() { }

//Set::Set(Card card) {
//    this->index = card.index;
//    this->onTable = card.onTable;
//    this->pix = card.pix;
//    this->selected = card.selected;
//}


// attribute |  0   |   1   |   2   |
//------------------------------------
// number    |  1   |   2   |   3   |
// shape     | dia  | oval  | squi  |
// shading   | no   | shade | solid |
// color     |  R   |   G   |   P   |

void Set::initialize(QVector<Card> &cards) {
    for(int i=0; i < totalCardNum+1; ++i) {
        cards[i].index = i;
        cards[i].num = (i-1) % 3;
        cards[i].shape = ((i-1) / 3) % 3;
        cards[i].shade = ((i-1) / 9) % 3;
        cards[i].color = ((i-1) / 27) % 3;
    }
}

int myRandGen(int i) {
    return rand()%i;
}

void Set::shuffle(QVector<Card> &cards) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    srand(seed);
    std::random_shuffle(cards.begin()+1, cards.end(), myRandGen);
}

void Set::print(QVector<Card> &cards) {
    for(Card card : cards) {
        qInfo() << card.index << " ";
    }
    qInfo() << "\n\n";
}

void Set::setInitialCards(QVector<Card> &cards, QVector<Card> &cardsOnTable) {
    if(cardsOnTable.size() == 0) { // initial case
        for(int i=0; i < tableCardNum; ++i) {
            cardsOnTable.push_back(cards.back());
            cards.pop_back();
        }
    }
}

// TODO: combine this to loadPix function
void Set::paintPixOn(QVector<Card> &cardsOnTable) {
    QRectF rect(0, 0, cardsOnTable[0].pixOff.width()-1, cardsOnTable[0].pixOff.height()-1);
    QPen pen("red");
    pen.setWidth(3);

    for(int i=0; i < cardsOnTable.size(); ++i) {
        QPainter painter;
        painter.begin(&cardsOnTable[i].pixOn);
        painter.setPen(pen);
        painter.drawRoundedRect(rect, 20, 20);
        painter.end();
    }
}

void Set::loadPix(QVector<Card> &cardsOnTable) {
    for(int i=0; i < cardsOnTable.size(); ++i){
        cardsOnTable[i].pixOff.load(QString("/Users/geonsookim/Desktop/qt-set/img/card%1.png").arg(cardsOnTable[i].index));
        cardsOnTable[i].pixOn.load(QString("/Users/geonsookim/Desktop/qt-set/img/card%1.png").arg(cardsOnTable[i].index));
    }
}

//void Set::ChoiceOfThreeOp(QVector<Card> &cardsOnTable, QList<ClickableLabel*> &childs, QVector<int> &clickedIndex) {
//    bool setCheck = isSet(cardsOnTable, clickedIndex);
//    for(int i=0; i < 3; ++i) {
//        childs[clickedIndex.front()]->setPixmap(cardsOnTable[clickedIndex.front()].pixOff);
//        cardsOnTable[clickedIndex.front()].selected = false;
//        clickedIndex.pop_front();
//    }
//}

bool Set::isSet(QVector<Card> &cardsOnTable, QVector<int> &clickedIndex) {
    qInfo() << QString("clikced size: %1").arg(clickedIndex.size());
    bool numPass = false;
    bool shapePass = false;
    bool shadePass = false;
    bool colorPass = false;

    int num[3], shape[3], shade[3], color[3];
    for(int i=0; i < 3; ++i) {
        num[i] = cardsOnTable[clickedIndex[i]].num;
        shape[i] = cardsOnTable[clickedIndex[i]].shape;
        shade[i] = cardsOnTable[clickedIndex[i]].shade;
        color[i] = cardsOnTable[clickedIndex[i]].color;
    }

    if((num[0] == num[1] && num[1] == num[2]) || (num[0] != num[1] && num[1] != num[2] && num[0] != num[2])) {
        numPass = true;
    }
    if((shape[0] == shape[1] && shape[1] == shape[2]) || (shape[0] != shape[1] && shape[1] != shape[2] && shape[0] != shape[2])) {
        shapePass = true;
    }
    if((shade[0] == shade[1] && shade[1] == shade[2]) || (shade[0] != shade[1] && shade[1] != shade[2] && shade[0] != shade[2])) {
        shadePass = true;
    }
    if((color[0] == color[1] && color[1] == color[2]) || (color[0] != color[1] && color[1] != color[2] && color[0] != color[2])) {
        colorPass = true;
    }

    if(numPass && shapePass && shadePass && colorPass) {
        return true;
    }
    return false;
}
