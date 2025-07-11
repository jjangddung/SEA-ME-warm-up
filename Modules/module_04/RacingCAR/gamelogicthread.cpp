// gamelogicthread.cpp
#include "gamelogicthread.h"
#include <QGraphicsRectItem>
#include <QRandomGenerator>

GameLogicThread::GameLogicThread(QGraphicsScene *scene, Car *car, QObject *parent)
    : QThread(parent), scene(scene), car(car) {}

void GameLogicThread::run() {
    while (running) {
        QThread::msleep(30);

        QMetaObject::invokeMethod(scene, [=]() {
            // 장애물 이동 및 제거
            for (QGraphicsItem *item : scene->items()) {
                if (item != car && dynamic_cast<QGraphicsRectItem *>(item)) {
                    item->moveBy(0, 5);
                    if (item->y() > 600) {
                        scene->removeItem(item);
                        delete item;
                    }
                }
            }

            if (QRandomGenerator::global()->bounded(20) == 0) {
                spawnObstacle();
            }

            checkCollisions();
        }, Qt::QueuedConnection);
    }
}

void GameLogicThread::spawnObstacle() {
    QGraphicsRectItem *obs = new QGraphicsRectItem(0, 0, 40, 40);
    obs->setBrush(Qt::blue);
    int x = QRandomGenerator::global()->bounded(60, 300); // 트랙 안쪽에서만
    obs->setPos(x, -40);
    scene->addItem(obs);
}

void GameLogicThread::checkCollisions() {
    for (QGraphicsItem *item : scene->collidingItems(car)) {
        if (item != car) {
            running = false;
            emit gameOver();
        }
    }
}
