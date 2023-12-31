#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QGraphicsRectItem>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initialiserScene();

public slots:
    //void closeEvent(QCloseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_btn_jouer_clicked();

private:
    Ui::MainWindow *ui;
    //créer la scène
    QGraphicsScene *scene;

    //créer un item à mettre dans la scène
    QGraphicsRectItem *rect;

    //
};
#endif // MAINWINDOW_H
