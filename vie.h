#ifndef VIE_H
#define VIE_H

#include <QGraphicsTextItem>

class vie: public QGraphicsTextItem
{
public:
    vie(QGraphicsTextItem *parent =0);
    void enleverVie();
    int getVie();

private:

    int pointVie;
};

#endif // VIE_H
