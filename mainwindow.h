#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QVector>
#include "set.h"

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
    void MousePressed();

private:
    Ui::MainWindow *ui;
    QVector<Set::Card> cardsOnTable;
    //int cnt;
    bool state = false;
};
#endif // MAINWINDOW_H
