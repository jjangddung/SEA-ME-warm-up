//변속기가 현재 엔진의 속도를 알고
#pragma once 
#include "Part.h"
#include <iostream>




class Transmission{
    private :
        int gear;
    
    public :
        Transmission(int g);
        void print() const override ;
        void set_gear(int n_g)  ; //const는 멤버 수정이 필요없을 때만

};