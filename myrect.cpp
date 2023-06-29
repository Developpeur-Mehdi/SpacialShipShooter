 #include "myrect.h"
#include <QDebug>
#include "balles.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "ennemi.h"
#include "game.h"


extern game *Game;

MyRect::MyRect(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    sonBalles = new QMediaPlayer();
    sonBalles->setMedia(QUrl("C:/Users/Dell/Documents/Informatique/Code en Vrac/jeu/jeu/laser-gun-shot.wav"));

    //dessiner joueur
    setPixmap(QPixmap("C:/Users/Dell/Documents/Informatique/Code en Vrac/jeu/jeu/vaisseau.jpg"));
}

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x() -10, y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 - 800)
        setPos(x() +10, y());
    }
//    else if (event->key() == Qt::Key_Up){
//        setPos(x(), y() -10);
//    }
//    else if (event->key() == Qt::Key_Down){
//        setPos(x(), y() +10);
//    }
    else if (event->key() == Qt::Key_Space){
        //créer une balle
        Balles *balles = new Balles();
        Balles *balles2 = new Balles();
        balles->setPos(x(), y());
        balles2->setPos(x() + 50, y());
        scene()->addItem(balles);
        scene()->addItem(balles2);

        //son balles
        if (sonBalles->state() == QMediaPlayer::PlayingState){
            sonBalles->setPosition(0);
        }
        else if (sonBalles->state() == QMediaPlayer::StoppedState){
            sonBalles->play();
        }
    }
}

/*void MyRect::supprimerEnnemi()
{
    if (Game->sante->getVie() == 0){
        scene()->removeItem(Ennemi);
        delete Ennemi;
    }
}*/

void MyRect::apparition()
{
    //créer un ennemi
    ennemi *Ennemi = new ennemi();
    scene()->addItem(Ennemi);

}
