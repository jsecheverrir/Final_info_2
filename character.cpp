#include "character.h"
#include <QPixmap>
#include <QGraphicsScene>
#include "macros_game.h"
#include "gameobject.h"

Character::Character()
    : GameObject(GameObject::Character, set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_1.png"), scale_factor)) {


    setPixmap(pixmap());
    setPos(x_inicial_personaje, y_inicial_personaje);
    moveSpeed = 2;

    Anim_Frame = 0;  //todo esto simplemente manejo de sprites, esto en funcion, load_sprites
    animation[Up].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_1.png"), scale_factor));
    animation[Up].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_2.png"), scale_factor));
    animation[Up].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_3.png"), scale_factor));
    animation[Up].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_4.png"), scale_factor));

    animation[Right].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_1.png"), scale_factor));
    animation[Right].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_2.png"), scale_factor));
    animation[Right].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_3.png"), scale_factor));
    animation[Right].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_4.png"), scale_factor));

    animation[Down].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_1.png"), scale_factor));
    animation[Down].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_2.png"), scale_factor));
    animation[Down].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_3.png"), scale_factor));
    animation[Down].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_4.png"), scale_factor));

    animation[Left].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_1.png"), scale_factor));
    animation[Left].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_2.png"), scale_factor));
    animation[Left].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_3.png"), scale_factor));
    animation[Left].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_4.png"), scale_factor));

}
/*
void Character::load_sprites() {  //ASSERT failure in QList::operator[]: "index out of range", file C:/Qt/6.6.1/mingw_64/include/QtCore/qlist.h, line 436
    Anim_Frame = 0;
    animation[Up].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_1.png"), scale_factor));
    animation[Up].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_2.png"), scale_factor));
    animation[Up].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_3.png"), scale_factor));
    animation[Up].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_4.png"), scale_factor));

    animation[Right].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_1.png"), scale_factor));
    animation[Right].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_2.png"), scale_factor));
    animation[Right].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_3.png"), scale_factor));
    animation[Right].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_4.png"), scale_factor));

    animation[Down].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_1.png"), scale_factor));
    animation[Down].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_2.png"), scale_factor));
    animation[Down].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_3.png"), scale_factor));
    animation[Down].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_4.png"), scale_factor));

    animation[Left].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_1.png"), scale_factor));
    animation[Left].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_2.png"), scale_factor));
    animation[Left].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_3.png"), scale_factor));
    animation[Left].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_4.png"), scale_factor));

}

int Character::getPosX() const {
    return posX;
}

int Character::getPosY() const {
    return posY;
}

int Character::getHealth() const {
    return health;
}

int Character::getStrength() const {
    return strength;
}

int Character::getResistance() const {
    return resistance;
}

void Character::setPosX(int _x) {
    posX = _x;
}

void Character::setPosY(int _y) {
    posY = _y;
}

void Character::setHealth(int _health) {
    health = _health;
}

void Character::setStrength(int _strength) {
    strength = _strength;
}

void Character::setResistance(int _resistance) {
    resistance = _resistance;
}
*/

void Character::moveUp() {  //metodos de movimiento, el problema es que esto no
    Anim_Frame++;
    if(Anim_Frame == animation[Up].size()) {
        Anim_Frame = 0;
    }
    setPixmap(animation[Up][Anim_Frame]);   //Frame de la animación
    setY(static_cast<int>(y()) - moveSpeed);          //Mover objeto
}

void Character::moveDown() {
    Anim_Frame++;
    if(Anim_Frame == animation[Down].size()) {
        Anim_Frame = 0;
    }
    setPixmap(animation[Down][Anim_Frame]);   //Frame de la animación
    setY(static_cast<int>(y()) + moveSpeed);          //Mover objeto
}

void Character::moveLeft() {
    Anim_Frame++;
    if(Anim_Frame == animation[Left].size()) {
        Anim_Frame = 0;
    }
    setPixmap(animation[Left][Anim_Frame]);   //Frame de la animación
    setX(static_cast<int>(x())- moveSpeed);          //Mover objeto
}

void Character::moveRight() {
    Anim_Frame++;
    if(Anim_Frame == animation[Right].size()) {
        Anim_Frame = 0;
    }
    setPixmap(animation[Right][Anim_Frame]);   //Frame de la animación
    setX(static_cast<int>(x())+ moveSpeed);          //Mover objeto
}
/*
void Character::takeDamage(int damage) {
    // calcular daño final usando resistencia
    int finalDamage = damage - (damage * resistance / 100);

    // actualizar vida con el daño por enemigo
    health -= finalDamage;
}
*/
