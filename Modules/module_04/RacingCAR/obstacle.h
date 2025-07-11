#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Obstacle : public QGraphicsPixmapItem {
public:
    Obstacle(const QPixmap &pixmap);
    void moveDown();
};

#endif // OBSTACLE_H
