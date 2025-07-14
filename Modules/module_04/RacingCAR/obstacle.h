#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Obstacle : public QGraphicsPixmapItem {
public:

    explicit Obstacle(const QPixmap &pixmap);

    // Rule of Three
    Obstacle(const Obstacle& other);
    Obstacle& operator=(const Obstacle& other);
    ~Obstacle();


    void moveDown();
};

#endif // OBSTACLE_H
