#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "gameobject.h"

class Character : public GameObject {
public:
    enum ObjectType { Heart, Orbe };

    Character();

    int getPosX() const;
    int getPosY() const;
    int getHealth() const;
    int getStrength() const;
    int getResistance() const;

    void setPosX(int _x);
    void setPosY(int _y);
    void setHealth(int _health);
    void setStrength(int _strength);
    void setResistance(int _resistance);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void takeDamage(int damage);

private:
    int posX;
    int posY;
    int health;
    int strength;
    int resistance;
    QGraphicsScene* scene;
    int Anim_Frame;
    QVector<QPixmap> animation[4];
};

#endif // CHARACTER_H
