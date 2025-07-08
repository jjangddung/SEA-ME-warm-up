#include <iostream>
#include "Brake.h"


Brake::Brake(bool br) : brake_on(br) {}

void Brake::print() const {
    std::cout << "Brake part\n";
    std::cout << "brake_on : " << brake_on << " \n";
}

void Brake::set_brake(bool on){
    brake_on = on ;
}
