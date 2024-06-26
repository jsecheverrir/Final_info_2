#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "QGraphicsPixmapItem"
#include <QLayout>
#include <QGraphicsScene>

#include "picture_management.h"
#include "gameobject.h"
#include "character.h"
#include "enemigo.h"
#include "game_rules.h"


class Character;
class GameObject;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    picture_management *img;
    QGraphicsScene *Scene;
    game_rules *game;

    void load_start_window();
    void load_game_window();
    void load_level_2();
    void load_level_3();
    void change_window_size(unsigned short width, unsigned short height);
    void resize_widget(QPixmap img, QWidget *obj);
    void set_off_windows();



private slots:
    void cambiar_pantalla();
    void keyPressEvent(QKeyEvent *k);
    void iniciarMovimientoEnemigo();



public slots:
};
#endif // MAINWINDOW_H
