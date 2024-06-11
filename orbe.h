#ifndef ORBE_H
#define ORBE_H
#include "gameobject.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "macros_game.h"
#include "gameobject.h"
#include "enemigo.h"


class Character;

class orbe :public QObject, public GameObject {
    float speed; //velocidad actual orbe
    float initialSpeed; //velocidad inicial
    float mass; //masa del orbe
    float force; //fuerza aplicada al orbe
    float timeInterval; //intervalo de tiempo de actualizacion


public:
    orbe();
    ~orbe();

    void moveOrbe();
    void startMoving();
    void enemShoot(int step);
    void setDirection(Direction direction);
    Enemigo *shooterEnemy;
    class Character *character;


private:
    QTimer *timer;
    QTimer *shootingTimer;




};

#endif // ORBE_H
