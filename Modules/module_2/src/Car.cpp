#include "Car.h"


Car::Car(std::shared_ptr<Engine> engine,
    std::array<std::shared_ptr<Wheel>,4> wheels, //위좌, 위우, 아좌. 아우
    std::array<std::shared_ptr<Brake>,4> Brakes,
    std::shared_ptr<Transmission> Transmission)
    : engine_(engine),wheels_(wheels),brakes_(Brakes),transmission_(Transmission) {}


void Car::prints_part() const {
    engine_->print();
    for (int i = 0 ; i < wheels_.size() ; i ++){
        std::cout << i << "번째 휠 \n " ;
        wheels_[i]->print() ;
    }
    for (int i = 0 ; i < wheels_.size() ; i ++){
        std::cout << i << "번째 브레이크 \n" ;
        brakes_[i]->print() ;
    }
    transmission_->print();
}

void Car::turn_left(){
    wheels_[2]->set_speed(10);
    std::cout << "left\n";
    wheels_[2]->print();
}

void Car::turn_right(){
    wheels_[1] ->set_speed(10);
    std::cout << "right\n";
    wheels_[1] ->print();
}

void Car::stop(){
    for (int i = 0 ; i < 4 ; i ++){
        brakes_[i]->set_brake(true);
        wheels_[i]->set_speed(0);
    }
}