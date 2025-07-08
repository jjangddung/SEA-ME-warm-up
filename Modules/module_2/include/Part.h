#pragma once
#include <iostream>


class Part{
    public :
        virtual void print() const =  0;
        virtual ~Part() = default ;

};