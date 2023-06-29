#include "score.h"
#include <QFont>

score::score(QGraphicsTextItem *parent): QGraphicsTextItem(parent)
{
    //initialiser score à 0
    resultat = 0;

    //dessiner le texte
    setPlainText(QString("Score: ") + QString::number(resultat)); //resultat = 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void score::augmenter()
{
    resultat++;
    setPlainText(QString("Score: ") + QString::number(resultat)); //resultat = 1
}

int score::getResultat()
{
    return resultat;
}
