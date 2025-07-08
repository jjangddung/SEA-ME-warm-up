#include <iostream>
#include <string>
#include "Wheel.h"



Wheel::Wheel(int sp) : speed(sp) {}

void Wheel::print() const{
    std::cout << "Wheel_speed: " << speed << "\n";
}

void Wheel::set_speed(int sp) {
    speed = sp ;
}