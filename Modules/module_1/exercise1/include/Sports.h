#pragma once
#include <bits/stdc++.h>
#include "Car.h"



class Sports : public Car {
    private :
        int* top_speed;
    public :
        Sports(const Car &car,int top_speed);
        ~Sports();
        Sports(const Sports&other);
        Sports& operator = (const Sports& other);

        void sports_drive() const;
};