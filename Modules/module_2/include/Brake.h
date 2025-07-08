#pragma once 
#include "Part.h"
#include <iostream>



class Brake : public Part{
    private : 
        bool brake_on  = false ;

    
    public :
        Brake(bool br = false);
        void print() const override ;
        bool set_brake(bool on) const ;



};