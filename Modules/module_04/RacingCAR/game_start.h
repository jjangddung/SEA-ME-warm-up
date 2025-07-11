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

signals:
    void startClicked();

protected:
    void resizeEvent(QResizeEvent *event) override;  // 🔄 크기 변경 대응

private:
    Ui::GameStart *ui;
    void updateBackground();  // 🔧 배경 이미지 설정 함수
};

#endif // GAME_START_H
