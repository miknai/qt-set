#ifndef SET_H
#define SET_H

#include <QVector>
#include <QPixmap>

class Set
{
public:
    Set();

    struct Card {
        int number;
        bool onTable = false;
        QPixmap pix;
    };

    static void initialize(QVector<Card> &cards);
    static void shuffle(QVector<Card> &cards);
    static void print(QVector<Card> &cards);
    static void putOnTable(QVector<Card> &cards, QVector<Card> &cardsOnTable);

    static const int totalCardNum = 81;
    static const int tableCardNum = 12;
};

#endif // SET_H
