#ifndef CAR_H
#define CAR_H

#include <QGraphicsPixmapItem>

class Car : public QGraphicsPixmapItem
{
public:

    explicit Car(const QPixmap &pixmap);


    Car(const Car& other);


    Car& operator=(const Car& other);


    ~Car();

    // 동작
    void moveLeft();
    void moveRight();
};

#endif // CAR_H
