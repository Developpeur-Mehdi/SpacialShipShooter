#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>
//#include "game.h"

class MyRect: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    MyRect(QGraphicsItem *parent = 0);

    void keyPressEvent(QKeyEvent *event);

public slots:
    void apparition();

private:
    QMediaPlayer *sonBalles;
    //ennemi *Ennemi = new ennemi();
};

#endif // MYRECT_H
