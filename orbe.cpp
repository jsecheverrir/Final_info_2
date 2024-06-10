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
    //connect(shootingTimer, &QTimer::timeout, this, &Enemigo::shoot);
}


void orbe::moveOrbe() {
    if (speed > 0) {
        // Aplicar el movimiento según la dirección del orbe
        if (direction == GameObject::Up) {
            setY(y() - speed); // Mover hacia arriba
        } else if (direction == GameObject::Down) {
            setY(y() + speed); // Mover hacia abajo
        }

        // Aplicar la fórmula F = m * a, donde F es la fuerza, m es la masa, y a es la aceleración.
        float acceleration = force / mass;

        // La nueva velocidad se calcula aplicando la aceleración: v = v0 + a * t.
        speed += acceleration * timeInterval;

        // Detección de colisiones
        QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);
        for (QGraphicsItem* item : collidingItems) {
            if (typeid(*item) == typeid(Enemigo)) {
                Enemigo *enemy = static_cast<Enemigo*>(item);
                if (enemy != shooterEnemy) { // Verificar si el enemigo no es el que disparó el orbe
                    qDebug() << "Colisión detectada con enemigo.";
                    scene()->removeItem(item); // Eliminar enemigo
                    scene()->removeItem(this); // Eliminar orbe
                    delete item;
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
    // Eliminar orbe si sale de escena, solo por precaución, aunque se debería borrar arriba siempre
    if (y() + pixmap().height() < 0) {
        timer->stop();
        scene()->removeItem(this);
        delete this;
    }
}



void orbe::setDirection(GameObject::Direction dir) {
    direction = dir;
}


void orbe::startMoving() {
    timer->start(static_cast<int>(timeInterval * 1000));  // Inicia el temporizador con el intervalo de tiempo en ms
}

void orbe::enemShoot(int step) {
    if (!step)
        return;

    // Mover hacia abajo utilizando la velocidad del orbe
    setY(y() + speed);

    qDebug() << "Moviendo la orbe hacia abajo desde orbe::enemShoot(). Posición actual: (" << x() << ", " << y() << ")";
}




orbe::~orbe() {
    delete timer;
}
