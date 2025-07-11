#include "obstacle.h"
#include <QTransform>

Obstacle::Obstacle(const QPixmap &pixmap)
    : QGraphicsPixmapItem() {
    QPixmap rotatedPixmap = pixmap.transformed(QTransform().rotate(270));  // 자동차 이미지 뒤집기
    setPixmap(rotatedPixmap.scaled(40, 60));  // 크기 줄이기
}

void Obstacle::moveDown() {
    moveBy(0, 5);  // 아래로 이동
}
