#ifndef GAME_RULES_H
#define GAME_RULES_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "character.h"
#include "enemigo.h"
#include <QVector>
#include "picture_management.h"
#include <QKeyEvent>
#include "macros_game.h"

class game_rules
{
public:
    game_rules(QGraphicsView *graph);
    static QPixmap background_picture(int level);
    void move_character(QKeyEvent *k);

private:
    QGraphicsView *graphics_scene;
    QGraphicsScene *scene;
    QVector<Enemigo *> total_enemies;
    Character *player;

    void load_level_1();
    void clear_elements();
    void load_level_2();
    void load_level_3();
};

#endif // GAME_RULES_H
