#ifndef BALLES_H
#define BALLES_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>
//#include "myrect.h"

class Balles: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Balles();
public slots:
    void move();
};

#endif // BALLES_H
