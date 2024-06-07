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
    // Coordenadas iniciales para el primer sprite de vida, poner macros

    QPixmap healthPixmap(":/sprites final/heart.png");

    float scaledWidth = healthPixmap.width() * life_scale; // Ajusta el factor de escala según sea necesario
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

void Character::moveUp() {  //metodos de movimiento
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

void Character::shootOrbe(QGraphicsScene* scene) {
    qDebug() << "Método shootOrbe() llamado";
    orbe *newOrbe = new orbe();
    qDebug() << "Nuevo orbe creado";

    // Establecemos la posición inicial del orbe
    newOrbe->setPos(x(), y());
    qDebug() << "Posición inicial del orbe establecida en:" << newOrbe->pos();

    // Verificamos si la escena está establecida
    if (scene) {
        qDebug() << "La escena está disponible";

        // Intentamos agregar el orbe a la escena
        if (newOrbe) {
            qDebug() << "Agregando el orbe a la escena";
            scene->addItem(newOrbe);
            qDebug() << "Orbe agregado a la escena";

            // Iniciamos el movimiento del orbe
            newOrbe->startMoving();
            qDebug() << "Movimiento del orbe iniciado";
        } else {
            qDebug() << "El orbe es nulo y no puede ser agregado a la escena";
        }
    } else {
        qDebug() << "La escena no está disponible";
    }
}








Character::~Character() {
    // Eliminar los sprites de vida creados anteriormente
    for (GameObject* lifeSprite : lifeSprites) {
        delete lifeSprite;
    }
    delete newOrbe;
}
