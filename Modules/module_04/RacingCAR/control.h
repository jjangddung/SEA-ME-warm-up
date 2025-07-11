#pragma once

class Control
{
private :

public:
    Control();
    ~Control();
    Control(const Control & other);
    Control operator = (const Control & other);
    void change_speed();
    void change_direction(); //rotate로 구현하자 degree에서 +-하는 정도로!!
                             // 반시계 방향으로 트랙을 구성할 것
};

