#include "Car.h"


Car::Car(std::shared_ptr<Engine> engine,
    std::array<std::shared_ptr<Wheel>,4> wheels, //위좌, 위우, 아좌. 아우
    std::array<std::shared_ptr<Brake>,4> Brakes,
    std::shared_ptr<Transmission> Transmission)
    : engine_(engine),wheels_(wheels),brakes_(Brake),transmission_(Transmission) {}


Car::prints_part(){
    engine_->print();
    for (auto w : wheels_){
        w->print();
    }
    for (auto b : brakes_){
        b->print();
    }
    transmission_->print();
}

void Car::turn_left(){
    wheels_[2].set_speed(10);
}

void Car::turn_right(){
    wheels_[1].set_speed(10);
}