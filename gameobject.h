#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class GameObject : public QGraphicsPixmapItem {
public:
    enum ObjectType { Character, Enemy, Life, Orbe, Obstacle };
    enum Direction { Up = 0, Down = 1, Left = 2, Right = 3, Stop = 4 };
    static const int width = 50; //tamaño objetos

    GameObject(ObjectType type, QPixmap pixmap);
    ~GameObject();

    ObjectType getType();
    int getPosX();
    void setPosX(int posX);
    int getPosY();
    void setPosY(int posY);
    Direction getDirection();
    Direction getNextDirection();
    void setDirection(Direction direction);
    void setNextDirection(Direction nextDirection);
    QPixmap set_scale(QPixmap img, int scale);
    Direction direction;

private:
    ObjectType type;
    int posX;
    int posY;

    Direction nextDirection;
};

#endif // GAMEOBJECT_H
