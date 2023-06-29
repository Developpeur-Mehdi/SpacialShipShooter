#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "myrect.h"
#include "score.h"
#include "vie.h"
#include "balles.h"


class game: public QGraphicsView
{
public:
    game(QWidget *parent = 0);
    QGraphicsScene *scene;
    MyRect *player;
    score *resulat;
    vie *sante;
};

#endif // GAME_H
