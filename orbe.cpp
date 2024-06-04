#include "orbe.h" //solo queda este
#include "gameobject.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "macros_game.h"

orbe::orbe():GameObject(GameObject::Orbe, QPixmap(":/sprites final/orbes personaje/orbes personaje.png")) {
    qDebug() << "Orbe constructor called.";
    setPixmap(set_scale(pixmap(), scale_factor));
    speed = 2;
}






orbe::~orbe() {
}
