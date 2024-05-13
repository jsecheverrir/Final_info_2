// enemigo.h

#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include "gameobject.h"
#include <QTimer>

class Enemigo : public QObject, public GameObject {

    Q_OBJECT
    int moveSpeed;
public:
    Enemigo(); // Constructor
     // Método para el movimiento automático
    void set_movement(bool is_in_movement);

private:
    int Anim_Frame;
    QVector<QPixmap> animation[4];
    QTimer *time;
    void loadSprites();

private slots:
    void moveAutomatically();
};

#endif // ENEMIGO_H
