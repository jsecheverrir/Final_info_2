#ifndef ORBE_H
#define ORBE_H
#include "gameobject.h"

class orbe : public GameObject{
    int speed;
public:
    orbe();
    void move();

private:
    QTimer *movementTimer;



};

#endif // ORBE_H
