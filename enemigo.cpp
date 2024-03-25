#include "enemigo.h"
#include <QPixmap>
#include <QGraphicsScene>
#include "macros_game.h"


Enemigo::Enemigo() :GameObject(GameObject::Enemy, QPixmap(":/sprites final/enemigo/enemigo_right_1.png"))  {

    setPixmap(pixmap());
    setPos(x_inicial_enemigo, y_inicial_enemigo);



}
