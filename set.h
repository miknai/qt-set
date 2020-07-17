#ifndef SET_H
#define SET_H

#include <QVector>
#include <QPixmap>

class Set
{
public:

    struct Card {
        int number;
        bool onTable = false;
        QPixmap pixOff;
        QPixmap pixOn;
        bool selected = false;
    };

    Set();
//    Set(Card card);

    static void initialize(QVector<Card> &cards);
    static void shuffle(QVector<Card> &cards);
    static void print(QVector<Card> &cards);
    static void putOnTable(QVector<Card> &cards, QVector<Card> &cardsOnTable);
    static void paintPixOn(QVector<Card> &cardsOnTable);
    static void loadPix(QVector<Card> &cardsOnTable);

    static const int totalCardNum = 81;
    static const int tableCardNum = 12;

//private:
//    int number;
//    bool onTable = false;
//    QPixmap pix;
//    bool selected = false;
};

#endif // SET_H
