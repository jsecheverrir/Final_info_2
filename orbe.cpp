#include "orbe.h"
#include "gameobject.h"
#include <QTimer>
#include <QGraphicsScene>

orbe::orbe():GameObject(GameObject::Orbe, QPixmap(":/sprites final/orbes personaje/orbes personaje.png")) {

    speed = 2;
    movementTimer = new QTimer;
    //connect(movementTimer, SIGNAL(timeout()), this, SLOT(move()));

}

void orbe::move() { //primer intento movimiento bala
    setPos(x() + speed, y());
    if (x() > scene()->width()) {
    }
}
