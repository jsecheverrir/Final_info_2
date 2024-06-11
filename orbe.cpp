#include "orbe.h" //solo queda este


orbe::orbe():GameObject(GameObject::Orbe, QPixmap(":/sprites final/orbes personaje/orbes personaje.png")) {
    setPixmap(set_scale(pixmap(), scale_orbe));
    initialSpeed = 10;
    speed = initialSpeed;
    mass = 0.5;
    force = -2.5; //fuerza de resistencia al viento, negativa para desacelerar el orbe
    timeInterval = 0.05; //50ms
    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &orbe::moveOrbe);
}


void orbe::moveOrbe() {
    if (speed > 0) {
        // Movimiento del orbe
        if (direction == GameObject::Up) {
            setY(y() - speed);
        } else if (direction == GameObject::Down) {
            setY(y() + speed);
        } else if (direction == GameObject::Left) {
            setX(x() - speed);
        } else if (direction == GameObject::Right) {
            setX(x() + speed);
        }

        float acceleration = force / mass;
        speed += acceleration * timeInterval;

        // Detección de colisiones
        QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);
        for (QGraphicsItem* item : collidingItems) {
            if (typeid(*item) == typeid(Enemigo)) {
                Enemigo *enemy = static_cast<Enemigo*>(item);
                if (enemy != shooterEnemy) { // Verifica si el enemigo no es el que disparó el orbe
                    qDebug() << "Colisión detectada con enemigo.";
                    enemy->applyPush(direction, 10); // Aplicar empuje al enemigo
                    enemy->handleCollision();

                    scene()->removeItem(this); // Eliminar el orbe, mirar si esto hace algo o si elimina el de abajo
                    delete this;
                    return;
                }
            }
        }
    } else {
        timer->stop();  // Detener el temporizador si la velocidad es cero o negativa
        scene()->removeItem(this); // Eliminar el orbe porque ya no tiene velocidad
        delete this;
    }
}



void orbe::setDirection(GameObject::Direction dir) {
    direction = dir;
}


void orbe::startMoving() {
    timer->start(static_cast<int>(timeInterval * 1000));  // Inicia el temporizador con el intervalo de tiempo en ms
}

void orbe::enemShoot(int step) { //creo que no sirve
    if (!step)
        return;
    setY(y() + speed);
}




orbe::~orbe() {
    delete timer;
}
