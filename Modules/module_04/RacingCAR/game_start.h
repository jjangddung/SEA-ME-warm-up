#ifndef GAME_START_H
#define GAME_START_H

#include <QWidget>

namespace Ui {
class GameStart;
}

class GameStart : public QWidget
{
    Q_OBJECT

public:
    explicit GameStart(QWidget *parent = nullptr);
    ~GameStart();

    // Rule of Three 적용 (복사 금지)
    GameStart(const GameStart&) = delete;
    GameStart& operator=(const GameStart&) = delete;

signals:
    void startClicked();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::GameStart *ui;
    void updateBackground();
};

#endif // GAME_START_H
