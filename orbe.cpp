#include "orbe.h" //solo queda este


orbe::orbe():GameObject(GameObject::Orbe, QPixmap(":/sprites final/orbes personaje/orbes personaje.png")) {
    setPixmap(set_scale(pixmap(), scale_orbe));
    speed = 2;
    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &orbe::moveOrbe);


}


void orbe::moveOrbe() {
    qDebug() << "Método moveOrbe() llamado. Posición actual:" << pos();

    // Movemos el orbe hacia arriba
    setY(y() - speed);
    qDebug() << "Orbe movido. Nueva posición:" << pos();

    // Si el orbe sale de la escena, lo eliminamos
    if (y() + pixmap().height() < 0) {
        qDebug() << "El orbe ha salido de la escena. Eliminando orbe.";
        if (scene()) {
            scene()->removeItem(this);
        }
        // Comentamos temporalmente la eliminación directa
        delete this;
    }
}




void orbe::startMoving() {
    qDebug() << "Método startMoving() llamado";
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &orbe::moveOrbe);
    timer->start(50);
    qDebug() << "Temporizador iniciado";
}




orbe::~orbe() {
}
