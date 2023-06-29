#include "vie.h"
#include <QFont>
#include "game.h"

//extern game* Game;

vie::vie(QGraphicsTextItem *parent): QGraphicsTextItem(parent)
{
    //initialiser 4 points de vie
    pointVie = 4;

    //dessiner le texte
    setPlainText(QString("Vie: ") + QString::number(pointVie)); //point de vie = 4
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 16));
}

void vie::enleverVie()
{
    pointVie--;
    setPlainText(QString("Vie: ") + QString::number(pointVie)); //point de vie = -1
}

int vie::getVie()
{
    return pointVie;
}
