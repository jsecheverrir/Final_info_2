#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "gameobject.h"
#include "orbe.h"

class Character :  public QObject, public GameObject {
    int moveSpeed;
    bool isJumping;
    float jumpSpeed;
    float jumpAcceleration;
    float initialJumpSpeed;
    QTimer *jumpTimer;
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
    void shootOrbe(QGraphicsScene* scene);
    void jump();
    void handleCollision();


private slots:
    void updatePosition();


private:
    int posX;
    int posY;
    int health;
    int maxHealth;
    int strength;
    int resistance;
    int Anim_Frame;
    int collisionCount;

    QGraphicsScene* scene;
    QVector<QPixmap> animation[4];
    std::vector<GameObject*> lifeSprites;
    Character* vida;
    orbe *newOrbe;

};

#endif // CHARACTER_H
