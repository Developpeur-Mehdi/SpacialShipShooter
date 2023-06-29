//#include "balles.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "ennemi.h"
#include "game.h"
#include "myrect.h"

extern game *Game; //variable globale

Balles::Balles(): QObject(), QGraphicsPixmapItem()
{
    //dessiner la balle
    //setRect(0, 0, 10, 50);
    setPixmap(QPixmap("C:/Users/Dell/Documents/Informatique/Code en Vrac/jeu/jeu/spaceBullet.jpg"));
    //connecter
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT (move()));

    timer->start(50);
}

void Balles::move()
{
    //si la balle rentre en collision, supprimer ennemi + balle
    QList <QGraphicsItem *> element_collision = collidingItems();
    for (int i = 0, j = element_collision.size(); i < j; ++i){
        if (typeid (*(element_collision[i])) == typeid (ennemi)){
            //augmenter le resultat
            Game->resulat->augmenter();
            //supprimer les deux
            scene()->removeItem(element_collision[i]);
            scene()->removeItem(this);
            delete element_collision[i];
            delete this;
            return;
        }
    }
    //animer la balle
    setPos(x(), y() -10);

    if (pos().y() /*+ rect()->height()*/ < 0){
        scene()->removeItem(this);
        delete this;
    }
}
