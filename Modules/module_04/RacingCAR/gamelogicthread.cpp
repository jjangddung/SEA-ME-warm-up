#include "gamelogicthread.h"
#include <QMetaObject>
#include <QThread>

GameLogicThread::GameLogicThread(QGraphicsScene* scene, Car* car, const QPixmap& obsPixmap, QObject* parent)
    : QThread(parent),
    scene(scene),
    car(car),
    obstaclePixmap(obsPixmap),
    gen(std::random_device{}()),
    dist(0, 359)
{}

void GameLogicThread::stop() {
    running = false;
}

void GameLogicThread::run() {
    running = true;
    int frameCounter = 0;

    while (running) {
        if (frameCounter % 20 == 0) {
            QMetaObject::invokeMethod(scene, [this]() {
                int x = dist(gen);
                auto* obs = new Obstacle(obstaclePixmap);
                obs->setPos(x, 0);
                scene->addItem(obs);
                obstacles.append(obs);
            }, Qt::QueuedConnection);
        }

        QMetaObject::invokeMethod(scene, [this]() {
            QList<Obstacle*> toRemove;

            for (Obstacle* obs : obstacles) {
                obs->moveDown();

                if (car && obs->collidesWithItem(car)) {
                    emit gameOver();
                    stop();
                    return;
                }

                if (obs->y() > 600) {
                    scene->removeItem(obs);
                    toRemove.append(obs);
                }
            }

            for (Obstacle* obs : toRemove) {
                obstacles.removeOne(obs);
                delete obs;
            }
        }, Qt::QueuedConnection);

        QThread::msleep(50);  // 20 FPS
        frameCounter++;
    }
}
