#ifndef ENNEMI_H
#define ENNEMI_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsPixmapItem>

class ennemi: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    ennemi();
public slots:
    void move();
};

#endif // ENNEMI_H
