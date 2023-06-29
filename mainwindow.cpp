#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    rect = new QGraphicsRectItem;
    rect->setRect(0, 0, 100, 100);

    //ajouter dansla scène
    scene->addItem(rect);
    //focaliser le rectangle
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();


    //ajouter la vue
    ui->graphicsView->setScene(scene);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete rect;
}

void MainWindow::initialiserScene()
{
    ui->graphicsView->setStyleSheet("background-color: #1A2D54");
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Q){
        rect->setPos(x() -10, y());
    }
    else if (event->key() == Qt::Key_D){
        rect->setPos(x() +10, y());
    }
    else if (event->key() == Qt::Key_Z){
        rect->setPos(x(), y() -10);
    }
    else if (event->key() == Qt::Key_S){
        rect->setPos(x(), y() +10);
    }
}

void MainWindow::on_btn_jouer_clicked()
{

}
