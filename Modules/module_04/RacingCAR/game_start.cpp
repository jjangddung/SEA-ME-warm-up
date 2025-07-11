#include "game_start.h"
#include "ui_game_start.h"
#include <QPixmap>
#include <QPalette>
#include <QResizeEvent>
#include <QDebug>

GameStart::GameStart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameStart)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);  // ✅ 배경 적용을 위해 필요

    // 첫 배경 설정
    updateBackground();

    // 버튼 클릭 시 startClicked 시그널 발신
    connect(ui->startButton, &QPushButton::clicked, this, &GameStart::startClicked);
}

GameStart::~GameStart()
{
    delete ui;
}

// 👉 resizeEvent 오버라이드해서 창 크기 변경 시 배경 다시 설정
void GameStart::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    updateBackground();
}

// ✅ 배경 이미지 설정 함수
void GameStart::updateBackground()
{
    QPixmap bg(":new/prefix1/images/background.jpg");  // 💡 .qrc에 있는 경로 기준

    if (!bg.isNull()) {
        QPalette palette;
        palette.setBrush(QPalette::Window,
                         QBrush(bg.scaled(this->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));
        this->setPalette(palette);
    } else {
        qDebug() << "🚨 배경 이미지 로드 실패!";
    }
}
