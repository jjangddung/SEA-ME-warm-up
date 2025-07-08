#pragma once
#include <string>
#include <iostream>
#include "Part.h"


class Engine : public Part {
    private:
        std::string Engine_name ;
        int Engine_pow ;

    public :
        Engine(std::string E_n = "default" ,int E_p = 100);
        void print() const  override; 
        
};