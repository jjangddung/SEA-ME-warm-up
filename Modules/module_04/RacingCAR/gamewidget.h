#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include "car.h"
#include "gamelogicthread.h"

class GameWidget : public QGraphicsView
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent = nullptr);
    ~GameWidget() override ;

    GameWidget(const GameWidget&) = delete;
    GameWidget& operator=(const GameWidget&) = delete;

    void startGame();

signals:
    void gameOver();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QGraphicsScene *scene;
    Car *car;
    QPixmap obstaclePixmap;
    GameLogicThread *gameThread;
};

#endif // GAMEWIDGET_H
