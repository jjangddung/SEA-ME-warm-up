#include "gamewidget.h"
#include "obstacle.h"
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QFile>
#include <QTransform>
#include <QTimer>
#include <cstdlib>

GameWidget::GameWidget(QWidget *parent)
    : QGraphicsView(parent),
    scene(new QGraphicsScene(this)),
    car(nullptr),
    spawnTimer(new QTimer(this)),
    moveTimer(new QTimer(this)) {

    setFixedSize(400, 600);
    scene->setSceneRect(0, 0, 400, 600);
    setScene(scene);

    // 🎨 배경 이미지 설정
    QPixmap background(":new/prefix1/images/track.jpg");
    if (!background.isNull()) {
        scene->setBackgroundBrush(background.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        qDebug() << "✅ 배경 이미지 로드 성공";
    } else {
        qDebug() << "🚨 배경 이미지 로드 실패!";
    }

    // 🚗 자동차 이미지 로드
    QPixmap carOriginal(":new/prefix1/images/sports_car.png");
    if (carOriginal.isNull()) {
        qDebug() << "🚨 자동차 이미지 로드 실패!";
        return;
    }

    QPixmap carPixmap = carOriginal.transformed(QTransform().rotate(-90), Qt::SmoothTransformation)
                            .scaledToWidth(40, Qt::SmoothTransformation);

    car = new Car(carPixmap);
    scene->addItem(car);
    car->setPos(175, 500);

    // 🚧 장애물 이미지 로드
    QPixmap obsPixmap(":new/prefix1/images/obstacle.png");
    if (obsPixmap.isNull()) {
        qDebug() << "🚨 장애물 이미지 로드 실패!";
        return;
    }

    obstaclePixmap = obsPixmap.scaled(40, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // 타이머 연결
    connect(spawnTimer, &QTimer::timeout, this, &GameWidget::spawnObstacle);
    connect(moveTimer, &QTimer::timeout, this, &GameWidget::moveObstacles);
}

void GameWidget::startGame() {
    spawnTimer->start(1000);
    moveTimer->start(50);
}

void GameWidget::spawnObstacle() {
    int x = rand() % 360;
    Obstacle *obs = new Obstacle(obstaclePixmap);
    obs->setPos(x, 0);
    scene->addItem(obs);
    obstacles.append(obs);
}

void GameWidget::moveObstacles() {
    QList<Obstacle*> toRemove;

    for (Obstacle *obs : obstacles) {
        obs->moveDown();

        if (car && obs->collidesWithItem(car)) {
            qDebug() << "💥 충돌 발생! 게임 종료!";
            spawnTimer->stop();
            moveTimer->stop();
            emit gameOver();
            return;
        }

        if (obs->y() > 600) {
            scene->removeItem(obs);
            toRemove.append(obs);
        }
    }

    for (Obstacle *obs : toRemove) {
        obstacles.removeOne(obs);
        delete obs;
    }
}

void GameWidget::keyPressEvent(QKeyEvent *event) {
    if (!car) return;

    if (event->key() == Qt::Key_Left) {
        car->moveLeft();
    } else if (event->key() == Qt::Key_Right) {
        car->moveRight();
    }
}
