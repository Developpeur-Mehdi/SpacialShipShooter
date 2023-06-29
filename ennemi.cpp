#include "ennemi.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"
#include <QMessageBox>

extern game *Game;

ennemi::ennemi(): QObject(), QGraphicsPixmapItem()
{
    //position aléatoire de l'ennemi
    int nombre_aleatoire = rand() % 700;
    setPos(nombre_aleatoire, 0);
    //dessiner l'ennemi
    //setRect(0, 0, 100, 100);
    setPixmap(QPixmap("C:/Users/Dell/Documents/Informatique/Code en Vrac/jeu/jeu/vaisseauEnnemi.jpg"));
    setTransformOriginPoint(50, 50);
    setRotation(180);
    //connecter
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT (move()));

    timer->start(50);
}

void ennemi::move()
{
    //QTimer *timer = new QTimer();
    //animer les ennemis
    setPos(x(), y() +5);

    if (Game->resulat->getResultat() >=  5)
    {
        setPos(x(), y() +5.5);
    }
    else if (Game->resulat->getResultat() >=  10)
    {
        setPos(x(), y() +6.5);
    }
    else if (Game->resulat->getResultat() >=  15)
    {
        setPos(x(), y() +7.5);
    }
    else if (Game->resulat->getResultat() >=  20)
    {
        setPos(x(), y() +8.5);
    }
    else if (Game->resulat->getResultat() >=  25)
    {
        setPos(x(), y() +9.5);
    }
    else if (Game->resulat->getResultat() >=  30)
    {
        setPos(x(), y() +11);
    }

    if (pos().y() > 600){
        //diminuer la santé
        Game->sante->enleverVie();

        if (Game->sante->getVie() == 0)
        {
            scene()->removeItem(this);
            delete this;

            //Game->player->supprimerEnnemi();
            Game->close();
            QMessageBox::information(nullptr, "Perdu", "Vous avez perdu !");
            //Game->close();
        }


//        scene()->removeItem(this);
//        delete this;
        //delete timer;
    }
}

