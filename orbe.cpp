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
    qDebug() << "Movimiento del orbe iniciado";
    if (speed > 0) {
        setY(y() - speed);

        // Aplicar la fórmula F = m * a, donde F es la fuerza, m es la masa, y a es la aceleración.
        float acceleration = force / mass;

        // La nueva velocidad se calcula aplicando la aceleración: v = v0 + a * t.
        speed += acceleration * timeInterval;

        qDebug() << "Velocidad actual del orbe:" << speed;

        // Detección de colisiones
        QList<QGraphicsItem*> collidingItems = scene()->collidingItems(this);
        for (QGraphicsItem* item : collidingItems) {
            if (typeid(*item) == typeid(Enemigo)) {
                qDebug() << "Colisión detectada con enemigo.";
                scene()->removeItem(item); // Eliminar enemigo
                scene()->removeItem(this); // Eliminar orbe
                delete item;
                delete this;
                return;
            }
        }
    } else {
        timer->stop();  // Detener el temporizador si la velocidad es cero o negativa
        qDebug() << "El orbe ha detenido su movimiento.";
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





void orbe::startMoving() {
    qDebug() << "Método startMoving() llamado";
    timer->start(static_cast<int>(timeInterval * 1000));  // Inicia el temporizador con el intervalo de tiempo en ms
    qDebug() << "Temporizador iniciado";
}





orbe::~orbe() {
    delete timer;
}
