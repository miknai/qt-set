#include "set.h"
#include <QVector>
//#include <QTimer>
#include <QDebug>
//#include <QRandomGenerator>
#include <algorithm>


Set::Set() { }

void Set::initialize(QVector<Card> &cards) {
    for(int i=0; i < cards.size(); ++i) {
        cards[i].number = i;
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
        qInfo() << card.number << " ";
    }
    qInfo() << "\n\n";
}

void Set::putOnTable(QVector<Card> &cards) {

}
