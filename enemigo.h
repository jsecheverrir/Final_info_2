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
    void set_movement(bool is_in_movement);
    QTimer *shootingTimer;
    //Enemigo *shooterEnemy;

private:
    int Anim_Frame;
    QVector<QPixmap> animation[4];
    QTimer *time;


    void loadSprites();
    void startMovingEnemy();


private slots:
    void moveAutomatically();
    void shoot();
};

#endif // ENEMIGO_H
