#pragma once
#include <iostream>
#include <string>
#include "Part.h"


class Wheel : public Part{
    private :
        int speed;

    public :
        Wheel(int sp = 50);
        void print() const override ;
        void set_speed(int sp);

};