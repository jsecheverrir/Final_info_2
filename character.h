#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "gameobject.h"
#include "orbe.h"

class Character : public GameObject {
    int moveSpeed;
public:
    enum ObjectType { Heart, Orbe };

    Character();
    ~Character();

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
    void load_sprites();
    void addLifeSpritesToScene(QGraphicsScene* scene);
    void shootOrbe();
    orbe* getOrbe() const;

public slots:


private:
    int posX;
    int posY;
    int health;
    int maxHealth;
    int strength;
    int resistance;
    int Anim_Frame;
    QGraphicsScene* scene;
    QVector<QPixmap> animation[4];
    std::vector<GameObject*> lifeSprites;
    Character* vida;
    orbe *newOrbe;
};

#endif // CHARACTER_H
