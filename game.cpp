#include "game.h"
#include <QApplication>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "ennemi.h"
#include "score.h"
#include <QMediaPlayer>
#include "balles.h"
#include <QImage>


game::game(QWidget *parent)
{
    setWindowTitle("SpatialShip shooter");
    //scene

    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    //mettre le fond
    setStyleSheet("background-color: #1a2d54");
    //setBackgroundBrush(QBrush(QImage(":/images/fondSpace.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    //créer joueur

    player = new MyRect();
    player->setPos(400, 500);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //créer le score et les points de vie

    resulat = new score();
    scene->addItem(resulat); //place directement en 0, 0
    //resulat->setPos(resulat->x(), resulat->y()+30);
    sante = new vie();
    sante->setPos(sante->x(), sante->y() +25);
    scene->addItem(sante);

    //apparition ennemi

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(apparition()));
    timer->start(1400);

    //lancer musique de fond
    QMediaPlayer *musique = new QMediaPlayer();
    musique->setMedia(QUrl("C:/Users/Dell/Documents/Informatique/Code en Vrac/jeu/jeu/musiquefond.wav"));
    //qrc:sounds/musiquefond.mp3
    //C:/Users/Dell/Documents/Informatique/Code en Vrac/jeu/jeu/musiquefond.mp3
    musique->play();

    show();
}
