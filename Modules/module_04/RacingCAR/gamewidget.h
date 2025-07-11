
#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "car.h"
#include "obstacle.h"

class GameWidget : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    void startGame();

signals:
    void gameOver();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void spawnObstacle();
    void moveObstacles();

private:
    QGraphicsScene *scene;
    Car *car;
    QList<Obstacle*> obstacles;
    QTimer *spawnTimer;
    QTimer *moveTimer;
    QPixmap obstaclePixmap;
};

#endif // GAMEWIDGET_H
