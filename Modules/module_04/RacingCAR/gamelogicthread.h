#ifndef GAMELOGICTHREAD_H
#define GAMELOGICTHREAD_H

#include <random>
#include <QThread>
#include <QGraphicsScene>
#include <QPixmap>
#include "car.h"
#include "obstacle.h"

class GameLogicThread : public QThread
{
    Q_OBJECT

public:
    explicit GameLogicThread(QGraphicsScene* scene, Car* car, const QPixmap& obsPixmap, QObject* parent = nullptr);
    ~GameLogicThread() override = default;

    GameLogicThread(const GameLogicThread&) = delete;
    GameLogicThread& operator=(const GameLogicThread&) = delete;

    void stop();

signals:
    void gameOver();

protected:
    void run() override;

private:
    QGraphicsScene* scene;
    Car* car;
    QList<Obstacle*> obstacles;
    QPixmap obstaclePixmap;
    bool running = false;
    std::mt19937 gen;
    std::uniform_int_distribution<> dist;
};

#endif // GAMELOGICTHREAD_H
