#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game_start.h"
#include "gamewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto *startScreen = new GameStart(this);
    setCentralWidget(startScreen);

    connect(startScreen, &GameStart::startClicked, this, [=]() {
        auto *gameWidget = new GameWidget(this);
        setCentralWidget(gameWidget);
        gameWidget->startGame();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
