#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>

#include "character.h"

#include "macros_game.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //time = new QTimer;
    set_off_windows();
    img = new picture_management;
    connect(ui->boton1, SIGNAL(clicked(bool)), this, SLOT(cambiar_pantalla()));

    // Crear una instancia de game_rules y asignarla a game, esto se queda

    //game = new game_rules(ui->graphicsView);

    load_start_window();
    //time->start(1000);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete img;
    delete Scene;
}

void MainWindow::load_start_window()
{
    QPixmap picture;

    change_window_size(xwindow, ywindow);
    ui->start_window->setGeometry(geometry());

    img->load_picture(":/sprites final/primera.png");
    picture = img->get_picture();
    resize_widget(picture, ui->start_img);

    ui->start_img->setPixmap(picture);
    ui->start_img->setGeometry(start_img_x, start_img_y, ui->start_img->width(), ui->start_img->height());
    ui->start_window->setVisible(true);
}

void MainWindow::load_game_window()
{
    QPixmap picture;

    ui->game_scene->setGeometry(0, 0, width(), height());
    ui->graphicsView->setGeometry(ui->game_scene->geometry());
    img->load_picture(":/sprites final/mapa 1.jpg");

    picture = img->get_picture();
    resize_widget(picture, ui->game_scene);

    character = new Character;
    enemigo = new Enemigo;



    QGraphicsScene *scene = new QGraphicsScene();
    scene->addPixmap(picture);
    scene->addItem(character);
    scene->addItem(enemigo);


    ui->graphicsView->setScene(scene);
    ui->game_scene->setVisible(true);
}

void MainWindow::change_window_size(unsigned short width, unsigned short height)
{
    setMaximumWidth(mainwindow_max_size);
    setMaximumHeight(mainwindow_max_size);
    setMinimumWidth(mainwindow_min_size);
    setMinimumHeight(mainwindow_min_size);
    setMaximumWidth(width);
    setMaximumHeight(height);
    setMinimumWidth(width);
    setMinimumHeight(height);
}

void MainWindow::resize_widget(QPixmap img, QWidget *obj)
{
    unsigned int width = img.width(), height = img.height();

    obj->setGeometry(obj->x(), obj->y(), width, height);
}

void MainWindow::set_off_windows()
{
    ui->start_window->setVisible(false);
    ui->game_scene->setVisible(false);
}

void MainWindow::cambiar_pantalla()
{
    set_off_windows();
    load_game_window();
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    switch (k->key()) {
    case Qt::Key_W:
        character->setNextDirection(GameObject::Up);
        character->moveUp();
        break;
    case Qt::Key_A:
        character->setNextDirection(GameObject::Left);
        character->moveLeft();
        break;
    case Qt::Key_S:
        character->setNextDirection(GameObject::Down);
        character->moveDown();
        break;
    case Qt::Key_D:
        character->setNextDirection(GameObject::Right);
        character->moveRight();
        break;
    }
}

