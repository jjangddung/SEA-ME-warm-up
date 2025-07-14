#include "game_start.h"
#include "ui_game_start.h"
#include <QPixmap>
#include <QPalette>
#include <QResizeEvent>
#include <QDebug>

GameStart::GameStart(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::GameStart)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);

    updateBackground();


    connect(ui->startButton, &QPushButton::clicked, this, &GameStart::startClicked);
}

GameStart::~GameStart()
{
    delete ui;
}


void GameStart::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    updateBackground();
}

void GameStart::updateBackground()
{
    QPixmap bg(":new/prefix1/images/background.jpg");

    if (!bg.isNull()) {
        QPalette palette;
        palette.setBrush(QPalette::Window,
                         QBrush(bg.scaled(this->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        this->setPalette(palette);
    } else {
        qDebug() << " 배경 이미지 로드 실패!";
    }
}
