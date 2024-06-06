#include "orbe.h" //solo queda este


orbe::orbe():GameObject(GameObject::Orbe, QPixmap(":/sprites final/orbes personaje/orbes personaje.png")) {
    setPixmap(set_scale(pixmap(), scale_orbe));
    speed = 2;
    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &orbe::moveOrbe);


}


void orbe::moveOrbe() {
    // Movemos el orbe hacia arriba
    qDebug() << "Método moveOrbe() llamado";
    setY(y() - speed);

    // Si el orbe sale de la escena, lo eliminamos
    if (y() + pixmap().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}

void orbe::startMoving() {
    qDebug() << "Método startMoving() llamado";
    timer->start(50); // Ajusta el intervalo de tiempo según sea necesario
    qDebug() << "Temporizador iniciado";
}




orbe::~orbe() {
}
