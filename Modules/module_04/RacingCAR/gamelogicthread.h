// gamelogicthread.h
#ifndef GAMELOGICTHREAD_H
#define GAMELOGICTHREAD_H

#include <QThread>
#include <QGraphicsScene>
#include "car.h"

class GameLogicThread : public QThread {
    Q_OBJECT

public:
    GameLogicThread(QGraphicsScene *scene, Car *car, QObject *parent = nullptr);

signals:
    void gameOver();

protected:
    void run() override;

private:
    QGraphicsScene *scene;
    Car *car;
    bool running = true;

    void spawnObstacle();
    void checkCollisions();
};

#endif // GAMELOGICTHREAD_H
