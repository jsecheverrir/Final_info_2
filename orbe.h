#ifndef ORBE_H
#define ORBE_H
#include "gameobject.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include "macros_game.h"

class orbe :public QObject, public GameObject {
    int speed;
public:
    orbe();
    ~orbe();

    void moveOrbe();
    void startMoving();


private:
    QTimer *timer;



};

#endif // ORBE_H
