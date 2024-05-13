#include "gameobject.h"

GameObject::GameObject(ObjectType t, QPixmap pixmap) : QGraphicsPixmapItem(pixmap)
{
    type = t; // Asignar el tipo de objeto
}

GameObject::~GameObject()
{

}

GameObject::ObjectType GameObject::getType()
{
    return type;
}

int GameObject::getPosX()
{
    return posX;
}

/*
void GameObject::setPosX(int posX)
{
    m_posX = posX;
}
*/

int GameObject::getPosY()
{
    return posY;
}

/*
void GameObject::setPosY(int posY)
{
    m_posY = posY;
}
*/

GameObject::Direction GameObject::getDirection()
{
    return direction;
}

void GameObject::setDirection(Direction dir)
{
    direction = dir;
}

GameObject::Direction GameObject::getNextDirection()
{
    return nextDirection;
}



void GameObject::setNextDirection(Direction dir)
{
    nextDirection = dir;
}

QPixmap GameObject::set_scale(QPixmap img, int scale)
{
    return img.scaled (img.width ()*scale,img.height ()*scale);
}
