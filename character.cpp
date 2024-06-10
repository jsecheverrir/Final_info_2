#include "character.h"
#include <QPixmap>
#include <QGraphicsScene>
#include "macros_game.h"
#include "gameobject.h"
#include <QKeyEvent>
#include "orbe.h"
#include <QTimer>
#include <QDebug>

Character::Character()
    : GameObject(GameObject::Character, QPixmap(":/sprites final/personaje sprites/personaje_right_1.png")) {
    setPixmap(set_scale(pixmap(), scale_factor));
    setPos(x_inicial_personaje, y_inicial_personaje);
    moveSpeed = 2;
    health = 3;
    maxHealth = 5;
    setFocus();
}

void Character::load_sprites() {
    // Limpiar los vectores de animación
    for (int i = 0; i < 4; ++i) {
        animation[i].clear();
    }

    for (int dir = 0; dir < 4; ++dir) {
        switch (dir) {
        case Up:
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_1.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_2.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_3.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_up_4.png"), scale_factor));
            break;
        case Right:
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_1.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_2.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_3.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_right_4.png"), scale_factor));
            break;
        case Down:
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_1.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_2.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_3.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_down_4.png"), scale_factor));
            break;
        case Left:
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_1.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_2.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_3.png"), scale_factor));
            animation[dir].push_back(set_scale(QPixmap(":/sprites final/personaje sprites/personaje_left_4.png"), scale_factor));
            break;
        }
    }
}
void Character::addLifeSpritesToScene(QGraphicsScene* scene) {
    QPixmap healthPixmap(":/sprites final/heart.png");
    float scaledWidth = healthPixmap.width() * life_scale;
    float scaledHeight = healthPixmap.height() * life_scale;
    QPixmap scaledHealthPixmap = healthPixmap.scaled(scaledWidth, scaledHeight);

    for (int i = 0; i < health; ++i) {
        // Crear un nuevo gameobject para representar el sprite de vida
        GameObject* lifeSprite = new GameObject(GameObject::Life, scaledHealthPixmap);
        lifeSprite->setPos(initialX + i * scaledWidth, initialY);
        scene->addItem(lifeSprite);
    }
}

int Character::getPosX() const {
    return posX;
}

int Character::getPosY() const {
    return posY;
}
/*
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

void Character::moveUp() {
    if (Anim_Frame < animation[Up].size()) {
        setPixmap(animation[Up][Anim_Frame]);   //Frame de la animación
    }
    setY(static_cast<int>(y()) - moveSpeed);   //Mover objeto
    Anim_Frame = (Anim_Frame + 1) % animation[Up].size();  // Incrementar frame de animacion
}

void Character::moveDown() {
    if (Anim_Frame < animation[Down].size()) {
        setPixmap(animation[Down][Anim_Frame]);   //Frame de la animación
    }
    setY(static_cast<int>(y()) + moveSpeed);   //Mover objeto
    Anim_Frame = (Anim_Frame + 1) % animation[Down].size();  // Incrementar frame de animacion
}

void Character::moveLeft() {
    if (Anim_Frame < animation[Left].size()) {
        setPixmap(animation[Left][Anim_Frame]);   //Frame de la animación
    }
    setX(static_cast<int>(x()) - moveSpeed);   //Mover objeto
    Anim_Frame = (Anim_Frame + 1) % animation[Left].size();  // Incrementar frame de animacion
}

void Character::moveRight() {
    if (Anim_Frame < animation[Right].size()) {
        setPixmap(animation[Right][Anim_Frame]);   //Frame de la animación
    }
    setX(static_cast<int>(x()) + moveSpeed);   //Mover objeto
    Anim_Frame = (Anim_Frame + 1) % animation[Right].size();  // Incrementar frame de animacion
}

void Character::shootOrbe(QGraphicsScene* scene) {
    orbe *newOrbe = new orbe();
    newOrbe->setDirection(GameObject::Up);
    newOrbe->setPos(x(), y());
    if (scene) {
        if (newOrbe) {
            scene->addItem(newOrbe);
            newOrbe->startMoving();
        } else {
        }
    } else {
    }
}








Character::~Character() {
    // Eliminar los sprites de vida creados anteriormente
    for (GameObject* lifeSprite : lifeSprites) {
        delete lifeSprite;
    }
    delete newOrbe;
}
