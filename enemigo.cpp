#include "enemigo.h"
#include <QPixmap>
#include <QGraphicsScene>
#include "macros_game.h"
#include <QTimer>
#include <QObject>
#include "game_rules.h"


Enemigo::Enemigo() :GameObject(GameObject::Enemy, QPixmap(":/sprites final/enemigo/enemigo_right_1.png"))  {

    time = new QTimer;
    shootingTimer = new QTimer;
    connect(time, SIGNAL(timeout()), this, SLOT(moveAutomatically()));
    connect(shootingTimer, &QTimer::timeout, this, &Enemigo::shoot);
    setPixmap(pixmap());
    setPos(x_inicial_enemigo, y_inicial_enemigo);
    //direction = Right;
    direction = Down;
    moveSpeed = 3;
    loadSprites();
    shootingTimer->start(2000);
    collisionCount = 0;
}

void Enemigo::loadSprites() {
    // Limpiamos la animación antes de cargar nuevos sprites, para que no haya animaciones anteriores en la lista
    for (int i = 0; i < 4; ++i) {
        animation[i].clear();
    }
    animation[Up].push_back(QPixmap(":/sprites final/enemigo/enemigo_up_1.png"));
    animation[Up].push_back(QPixmap(":/sprites final/enemigo/enemigo_up_2.png"));
    animation[Up].push_back(QPixmap(":/sprites final/enemigo/enemigo_up_3.png"));
    animation[Up].push_back(QPixmap(":/sprites final/enemigo/enemigo_up_4.png"));

    animation[Right].push_back(QPixmap(":/sprites final/enemigo/enemigo_right_1.png"));
    animation[Right].push_back(QPixmap(":/sprites final/enemigo/enemigo_right_2.png"));
    animation[Right].push_back(QPixmap(":/sprites final/enemigo/enemigo_right_3.png"));
    animation[Right].push_back(QPixmap(":/sprites final/enemigo/enemigo_right_4.png"));

    animation[Down].push_back(QPixmap(":/sprites final/enemigo/enemigo_down_1.png"));
    animation[Down].push_back(QPixmap(":/sprites final/enemigo/enemigo_down_2.png"));
    animation[Down].push_back(QPixmap(":/sprites final/enemigo/enemigo_down_3.png"));
    animation[Down].push_back(QPixmap(":/sprites final/enemigo/enemigo_down_4.png"));

    animation[Left].push_back(QPixmap(":/sprites final/enemigo/enemigo_left_1.png"));
    animation[Left].push_back(QPixmap(":/sprites final/enemigo/enemigo_left_2.png"));
    animation[Left].push_back(QPixmap(":/sprites final/enemigo/enemigo_left_3.png"));
    animation[Left].push_back(QPixmap(":/sprites final/enemigo/enemigo_left_4.png"));
}

void Enemigo::moveAutomatically() {
    int newX = x();
    int newY = y();
    if (direction == Right) {
        newX += moveSpeed;
        if (newX >= maxRight)
            direction = Left;
    } else if (direction == Left) {
        newX -= moveSpeed;
        if (newX <= maxLeft)
            direction = Right;
    }
    if (direction == Up) {
        newY -= moveSpeed;
        if (newY <= maxTop)
            direction = Down;
    } else if (direction == Down) {
        newY += moveSpeed;
        if (newY >= maxBottom)
            direction = Up;
    }
    setX(newX);
    setY(newY);
    if (animation[direction].size() > 0) {
        Anim_Frame = (Anim_Frame + 1) % animation[direction].size(); // Incrementar frame de animacion
        setPixmap(animation[direction][Anim_Frame]);
    }
}


void Enemigo::set_movement(bool is_in_movement)
{
    if(is_in_movement) time->start(50);
    else time->stop();
}



void Enemigo::shoot() {
    orbe *enemyOrbe = new orbe;
    enemyOrbe->setDirection(GameObject::Down);
    enemyOrbe->setPos(this->x(), this->y());
    enemyOrbe->shooterEnemy = this;
    if (this->scene()) {
        if (enemyOrbe) {
            this->scene()->addItem(enemyOrbe);
            enemyOrbe->startMoving();
        } else {
        }
    } else {
    }
}

void Enemigo::applyPush(Direction direction, float pushForce) { //segunda fisica
    if (direction == Right) {
        setX(x() + pushForce);
    } else if (direction == Left) {
        setX(x() - pushForce);
    } else if (direction == Up) {
        setY(y() - pushForce);
    } else if (direction == Down) {
        setY(y() + pushForce);
    }
}

void Enemigo::handleCollision() {
    collisionCount++;
    if (collisionCount >= 3) {
        // El enemigo muere
        scene()->removeItem(this);
        delete this;
    }
}
