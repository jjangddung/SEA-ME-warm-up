#ifndef CAR_H
#define CAR_H

#include <QGraphicsPixmapItem>

class Car : public QGraphicsPixmapItem
{
public:
    Car(const QPixmap &pixmap);
    void moveLeft();
    void moveRight();
};

#endif // CAR_H
