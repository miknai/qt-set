#ifndef SET_H
#define SET_H

#include <QVector>
#include <QPixmap>
#include "clickablelabel.h"

class Set
{
public:

    struct Card {
        int index;
        bool onTable = false;
        QPixmap pixOff;
        QPixmap pixOn;
        bool selected = false;
        int num;
        int shape;
        int shade;
        int color;
    };

    Set();
    Set(int size);
//    Set(Card card);

//    QString operator [] (Card) const;

    static void initialize(QVector<Card> &cards);
    static void shuffle(QVector<Card> &cards);
    static void print(QVector<Card> &cards);
    static void setInitialCards(QVector<Card> &cards, QVector<Card> &cardsOnTable);
    static void paintPixOn(QVector<Card> &cardsOnTable);
    static void loadPix(QVector<Card> &cardsOnTable);
//    static void ChoiceOfThreeOp(QVector<Card> &cardsOnTable, QList<ClickableLabel*> &childs, QVector<int> &clickedIndex);
    static bool isSet(QVector<Card> &cardsOnTable, QVector<int> &clickedIndex);

    static const int totalCardNum = 81;
    static const int tableCardNum = 12;

//private:
//    int index;
//    bool onTable = false;
//    QPixmap pix;
//    bool selected = false;
};

#endif // SET_H
