#include "gamewidget.h"
#include "obstacle.h"
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QFile>
#include <QTransform>

GameWidget::GameWidget(QWidget *parent)
    : QGraphicsView(parent),
    scene(new QGraphicsScene(this)),
    car(nullptr),
    gameThread(nullptr)
{
    setFixedSize(400, 600);
    scene->setSceneRect(0, 0, 400, 600);
    setScene(scene);


    QPixmap bg(":new/prefix1/images/track.jpg");
    if (!bg.isNull()) {
        scene->setBackgroundBrush(bg.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }


    QPixmap carPixmap(":new/prefix1/images/sports_car.png");
    if (carPixmap.isNull()) {
        qDebug() << "🚗 자동차 이미지 로드 실패";
        return;
    }
    carPixmap = carPixmap.transformed(QTransform().rotate(-90)).scaledToWidth(40);
    car = new Car(carPixmap);
    scene->addItem(car);
    car->setPos(175, 500);


    QPixmap obsPixmap(":new/prefix1/images/obstacle.png");
    if (obsPixmap.isNull()) {
        qDebug() << "🚧 장애물 이미지 로드 실패";
        return;
    }
    obstaclePixmap = obsPixmap.scaled(40, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation);


    gameThread = new GameLogicThread(scene, car, obstaclePixmap, this);
    connect(gameThread, &GameLogicThread::gameOver, this, [=]() {
        qDebug() << "💥 충돌! 게임 종료";
    });
}





GameWidget::~GameWidget() {
    if (gameThread && gameThread->isRunning()) {
        gameThread->stop();
        gameThread->wait();
    }
}


void GameWidget::startGame() {
    if (gameThread)
        gameThread->start();
}

void GameWidget::keyPressEvent(QKeyEvent *event) {
    if (!car) return;

    switch (event->key()) {
    case Qt::Key_Left:
        car->moveLeft();
        break;
    case Qt::Key_Right:
        car->moveRight();
        break;
    }
}
