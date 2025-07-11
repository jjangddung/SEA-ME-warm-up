#include "car.h"

Car::Car(const QPixmap &pixmap)
{
    setPixmap(pixmap);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Car::moveLeft()
{
    setPos(pos() + QPointF(-10, 0));
}

void Car::moveRight()
{
    setPos(pos() + QPointF(10, 0));
}
