#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QObject>
#include "gameobject.h"
#include <QTimer>



class Enemigo : public QObject, public GameObject {

    Q_OBJECT
    int moveSpeed;
public:
    Enemigo();
    void set_movement(bool is_in_movement);
    QTimer *shootingTimer;
    void applyPush(Direction direction, float pushForce);
    void handleCollision();
    int getCollisionCount() const;



private:
    int Anim_Frame;
    QVector<QPixmap> animation[4];
    QTimer *time;
    int collisionCount;
    void loadSprites();
    void startMovingEnemy();



private slots:
    void moveAutomatically();
    void shoot();
};

#endif // ENEMIGO_H
