#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class score: public QGraphicsTextItem
{
public:
    score(QGraphicsTextItem *parent = 0);
    void augmenter();
    int getResultat();
private:

    int resultat;
};

#endif // SCORE_H
