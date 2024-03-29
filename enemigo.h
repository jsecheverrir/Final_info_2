// enemigo.h

#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "gameobject.h"

class Enemigo : public GameObject {
    int moveSpeed;
public:
    Enemigo(); // Constructor
    void moveAutomatically(); // Método para el movimiento automático

private:
    int Anim_Frame;
    QVector<QPixmap> animation[4];
};

#endif // ENEMIGO_H
