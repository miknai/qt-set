#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QVector>
#include "set.h"
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void MousePressed(int labelNum);
    //void MousePressed2();

private:
    Ui::MainWindow *ui;
    QVector<Set::Card> cards;
    QVector<Set::Card> cardsOnTable;
    QVector<int> clickedIndex;
    QList<ClickableLabel*> childs;
    //int cnt;
    bool state = false;
    bool state2 = false;

};
#endif // MAINWINDOW_H
