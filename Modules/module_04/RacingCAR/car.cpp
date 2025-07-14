#include "car.h"

Car::Car(const QPixmap &pixmap)
{
    setPixmap(pixmap);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}


Car::Car(const Car& other)
{
    setPixmap(other.pixmap());
    setPos(other.pos());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}


Car& Car::operator=(const Car& other)
{
    if (this != &other) {
        setPixmap(other.pixmap());
        setPos(other.pos());
        setFlag(QGraphicsItem::ItemIsFocusable);
        setFocus();
    }
    return *this;
}


Car::~Car()
{
}

void Car::moveLeft()
{
    setPos(pos() + QPointF(-10, 0));
}

void Car::moveRight()
{
    setPos(pos() + QPointF(10, 0));
}
