#include "game_rules.h"

game_rules::game_rules(QGraphicsView *graph) {
    graphics_scene = graph;
    player = new Character;
    scene = new QGraphicsScene;
    graphics_scene->setScene (scene);

    load_level_1();
    //load_level_2();
    //load_level_3();

}

QPixmap game_rules::background_picture(int level)
{
    picture_management img;

    if(level==1) img.load_picture(":/sprites final/mapa 1.jpg");
    if (level==2) img.load_picture (":/sprites final/mapa 2.jpg");
    if (level==3) img.load_picture (":/sprites final/mapa 3.jpg");

    return img.get_picture();
}

void game_rules::setupEnemyDirection(Enemigo *enemy, int level) {
    if (level == 1) {
        enemy->setNextDirection(GameObject::Right);
    } else if (level == 2) {
        enemy->setNextDirection(GameObject::Down);
    } else if (level == 3) {
        enemy->setNextDirection(GameObject::Right);
    }
}

void game_rules::move_character(QKeyEvent *k)
{
    switch (k->key()) {
    case Qt::Key_W:
        player->setNextDirection(GameObject::Up);
        player->load_sprites();
        player->moveUp();
        break;
    case Qt::Key_A:
        player->setNextDirection(GameObject::Left);
        player->load_sprites();
        player->moveLeft();
        break;
    case Qt::Key_S:
        player->setNextDirection(GameObject::Down);
        player->load_sprites();
        player->moveDown();
        break;
    case Qt::Key_D:
        player->setNextDirection(GameObject::Right);
        player->load_sprites();
        player->moveRight();
        break;
    }
}


void game_rules::load_level_1()
{
    picture_management img;

    clear_elements();
    total_enemies.append (new Enemigo);

    img.load_picture(":/sprites final/mapa 1.jpg");
    scene->addPixmap (img.get_picture ());
    scene->addItem(player);
    player->addLifeSpritesToScene(scene);

    for(int i=0;i<total_enemies.length ();i++){
        total_enemies[i]->set_movement (true);
        scene->addItem(total_enemies[i]);
    }
}

void game_rules::clear_elements()
{
    scene->clear();
    for(int i=0;i<total_enemies.length ();i++) delete total_enemies[i];
    total_enemies.clear ();
}

void game_rules::load_level_2()
{
    picture_management img;


    clear_elements();
    //total_enemies.append(new Enemigo);

    img.load_picture (":/sprites final/mapa 2.jpg");
    scene->addPixmap (img.get_picture ());
    player->setPos(x_inicial_2, y_inicial_2);
    scene->addItem (player);
    player->addLifeSpritesToScene(scene);

    int num_enemies = 2;
    for (int i = 0; i < num_enemies; ++i) {
        total_enemies.append(new Enemigo);
        total_enemies[i]->setPos(enemigo_2x + i * distanciaenemigos, enemigo_2y);
        total_enemies[i]->set_movement(true);
        scene->addItem(total_enemies[i]);
    }
    for(int i=0;i<total_enemies.length ();i++){
        total_enemies[i]->set_movement (true);
        scene->addItem(total_enemies[i]);
    }

}

void game_rules::load_level_3() {
    clear_elements();
    QPixmap background(":/sprites final/mapa 3.jpg");
    if (!background.isNull()) {
        scene->addPixmap(background);
    } else {
    }
    player->setPos(x_inicial_3, y_inicial_3);
    scene->addItem(player);
    player->addLifeSpritesToScene(scene);

    int num_enemies = 1;
    for (int i = 0; i < num_enemies; ++i) {
        Enemigo* enemy = new Enemigo();
        enemy->setPos(enemigo_3x, enemigo_3y);
        total_enemies.append(enemy);
        scene->addItem(enemy);
    }

}


void game_rules::shoot(QKeyEvent *k) {
    switch (k->key()) {
    case Qt::Key_O:
        if (player) {
            player->shootOrbe(scene);
        } else {
        }
        break;
    }
}


