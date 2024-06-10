#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>

#include "macros_game.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    set_off_windows();
    img = new picture_management;
    game = new game_rules(ui->graphicsView);
    connect(ui->boton1, SIGNAL(clicked(bool)), this, SLOT(cambiar_pantalla()));
    load_start_window();
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
    // Agregar un título
    QLabel *titleLabel1 = new QLabel("DinoCrisis", ui->start_window);
    QFont titleFont1 = titleLabel1->font();
    titleFont1.setPointSize(24);
    titleFont1.setBold(true);
    titleLabel1->setFont(titleFont1);
    titleLabel1->setAlignment(Qt::AlignCenter);

    // Calcular la posición vertical del primer título
    int titleX1 = (ui->start_window->width() - titleLabel1->width()) / 2;
    int titleY1 = 50; // Ajusta la posición vertical del primer título según sea necesario

    // Establecer la posición del primer título
    titleLabel1->move(titleX1, titleY1);

    // Agregar el título "La última batalla"
    QLabel *titleLabel2 = new QLabel("La última batalla", ui->start_window);
    QFont titleFont2 = titleLabel2->font();
    titleFont2.setPointSize(18);
    titleFont2.setBold(true);
    titleLabel2->setFont(titleFont2);
    titleLabel2->setAlignment(Qt::AlignCenter);

    // Calcular la posición vertical del segundo título
    int titleX2 = (ui->start_window->width() - titleLabel2->width()) / 2;
    int titleY2 = 100; // Ajusta la posición vertical del segundo título según sea necesario

    // Establecer la posición del segundo título
    titleLabel2->move(titleX2, titleY2);
    ui->start_window->setVisible(true);
}

void MainWindow::load_game_window()
{
    ui->game_scene->setGeometry(0, 0, width(), height());
    ui->graphicsView->setGeometry(ui->game_scene->geometry());
    resize_widget(game_rules::background_picture(1), ui->game_scene);
    ui->game_scene->setVisible(true);
}


void MainWindow::load_level_2(){
    ui->game_scene->setGeometry(0, 0, width(), height());
    ui->graphicsView->setGeometry(ui->game_scene->geometry());
    resize_widget(game_rules::background_picture(2), ui->game_scene);
    ui->game_scene->setVisible(true);
}

void MainWindow::load_level_3(){
    ui->game_scene->setGeometry(0, 0, width(), height());
    ui->graphicsView->setGeometry(ui->game_scene->geometry());
    resize_widget(game_rules::background_picture(3), ui->game_scene);
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
    ui->level_2_scene->setVisible(false);

}

void MainWindow::cambiar_pantalla()
{
    static int i=0;
    set_off_windows();
    if(i%2==0) load_game_window();
    else load_level_2();
    i++;
}

void MainWindow::keyPressEvent(QKeyEvent *k)
{
    game->move_character(k);
    game->shoot (k);
    game->jump(k);
}



void MainWindow::iniciarMovimientoEnemigo() {
    //enemigo->moveAutomatically();
}


