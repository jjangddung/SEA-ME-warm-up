//현재의 기어와 속도를 입력받음
//그리고 시간에 따라 점차 속도가 증가함
//만약 기어[transmission] = 1인데, wheel 속도가 50이라면,
//시간에 따라 속도가 증가함을 프린트 max speed라면 기어를 풀고 속도 제한을 올림 
//기어를 가변해서 최대 속도를 올려줌
//brake에 신호가 들어왔다면, wheel 속도를 0으로 만듬
//이것들을 고려해서 Class Car를 만들어보자.

#pragma once 
#include "Part.h"
#include "Brake.h"
#include "Engine.h"
#include "Wheel.h"
#include "Transmission.h"
#include <vector>
#include <memory>
#include <array>





class Car {
    private :
        std::shared_ptr<Engine> engine_;
        std::array<std::shared_ptr<Wheel>,4> wheels_;
        std::array<std::shared_ptr<Brake>,4> brakes_;
        std::shared_ptr<Transmission> transmission_;
    
    public :
        Car(std::shared_ptr<Engine> engine,
            std::array<std::shared_ptr<Wheel>,4> wheels,
            std::array<std::shared_ptr<Brake>,4> Brakes,
            std::shared_ptr<Transmission> Transmission);

        void prints_part() const ;

        void turn_right() ;
        
        void turn_left();

        void stop();


};