#include "enemigo.h"
#include <QPixmap>
#include <QGraphicsScene>
#include "macros_game.h"
#include <QTimer>
#include <QObject>


Enemigo::Enemigo() :GameObject(GameObject::Enemy, QPixmap(":/sprites final/enemigo/enemigo_right_1.png"))  {

    setPixmap(pixmap());
    setPos(x_inicial_enemigo, y_inicial_enemigo);
    direction = Right;
    moveSpeed = 2;
    loadSprites();


}

void Enemigo::loadSprites() {
    // Limpiamos la animación antes de cargar nuevos sprites, para que no haya animaciones anteriores en la lista
    for (int i = 0; i < 4; ++i) {
        animation[i].clear();
    }

    // Carga de sprites para cada dirección
    animation[Up].push_back(QPixmap(":/sprites final/enemigo/enemigo_up_1.png"));
    animation[Up].push_back(QPixmap(":/sprites final/enemigo/enemigo_up_2.png"));
    animation[Up].push_back(QPixmap(":/sprites final/enemigo/enemigo_up_3.png"));
    animation[Up].push_back(QPixmap(":/sprites final/enemigo/enemigo_up_4.png"));
    animation[Up].push_back(QPixmap(":/sprites final/enemigo/enemigo_up_5.png"));

    animation[Right].push_back(QPixmap(":/sprites final/enemigo/enemigo_right_1.png"));
    animation[Right].push_back(QPixmap(":/sprites final/enemigo/enemigo_right_2.png"));
    animation[Right].push_back(QPixmap(":/sprites final/enemigo/enemigo_right_3.png"));
    animation[Right].push_back(QPixmap(":/sprites final/enemigo/enemigo_right_4.png"));
    animation[Right].push_back(QPixmap(":/sprites final/enemigo/enemigo_right_5.png"));

    animation[Down].push_back(QPixmap(":/sprites final/enemigo/enemigo_down_1.png"));
    animation[Down].push_back(QPixmap(":/sprites final/enemigo/enemigo_down_2.png"));
    animation[Down].push_back(QPixmap(":/sprites final/enemigo/enemigo_down_3.png"));
    animation[Down].push_back(QPixmap(":/sprites final/enemigo/enemigo_down_4.png"));
    animation[Down].push_back(QPixmap(":/sprites final/enemigo/enemigo_down_5.png"));

    animation[Left].push_back(QPixmap(":/sprites final/enemigo/enemigo_left_1.png"));
    animation[Left].push_back(QPixmap(":/sprites final/enemigo/enemigo_left_2.png"));
    animation[Left].push_back(QPixmap(":/sprites final/enemigo/enemigo_left_3.png"));
    animation[Left].push_back(QPixmap(":/sprites final/enemigo/enemigo_left_4.png"));
    animation[Left].push_back(QPixmap(":/sprites final/enemigo/enemigo_left_5.png"));
}

void Enemigo::moveAutomatically() {
    int newX = x();
    if (direction == Right) {
        newX += moveSpeed;
        if (newX >= maxRight)
            direction = Left;
    } else {
        newX -= moveSpeed;
        if (newX <= maxLeft)
            direction = Right;
    }
    setX(newX);
    if (direction == Up) {
        setPixmap(animation[Up][Anim_Frame]);
    } else if (direction == Right) {
        setPixmap(animation[Right][Anim_Frame]);
    } else if (direction == Down) {
        setPixmap(animation[Down][Anim_Frame]);
    } else if (direction == Left) {
        setPixmap(animation[Left][Anim_Frame]);
    }

    Anim_Frame = (Anim_Frame + 1) % animation[direction].size(); // Incrementar frame de animacion
}
