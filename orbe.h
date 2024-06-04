#ifndef ORBE_H
#define ORBE_H
#include "gameobject.h"

class orbe :public QObject, public GameObject {
    int speed;
public:
    orbe();
    ~orbe();


private:




};

#endif // ORBE_H
