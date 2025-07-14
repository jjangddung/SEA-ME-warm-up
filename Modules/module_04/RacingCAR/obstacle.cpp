#include "obstacle.h"
#include <QTransform>

Obstacle::Obstacle(const QPixmap &pixmap)
    : QGraphicsPixmapItem()
{
    QPixmap rotatedPixmap = pixmap.transformed(QTransform().rotate(270));
    setPixmap(rotatedPixmap.scaled(40, 60));
}


Obstacle::Obstacle(const Obstacle& other)
    : QGraphicsPixmapItem()
{
    setPixmap(other.pixmap());
    setPos(other.pos());
    setRotation(other.rotation());
}


Obstacle& Obstacle::operator=(const Obstacle& other)
{
    if (this != &other) {
        setPixmap(other.pixmap());
        setPos(other.pos());
        setRotation(other.rotation());
    }
    return *this;
}


Obstacle::~Obstacle()
{

}

void Obstacle::moveDown()
{
    moveBy(0, 5);
}
