#include <iostream>
#include <string>
#include "Engine.h"




Engine::Engine(std::string E_n, int E_p) : Engine_name(E_n),Engine_pow(E_p){}
void Engine::print() const {
    std::cout << "Engine_part \n";
    std::cout << "Engine_name : " << Engine_name << "\n"
              << "Engine_power : " << Engine_power << "\n";
}

