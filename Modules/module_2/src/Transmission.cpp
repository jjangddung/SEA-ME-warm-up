#include "Transmission.h"
#include <iostream>



Transmission::Transmission(int g = 1) : gear(g) {}
void Transmission::print() const {
    std:: cout << "Gear : " << gear  << "\n";
}
void Transmission::set_gear(int n_g) {
    gear = n_g;
}

