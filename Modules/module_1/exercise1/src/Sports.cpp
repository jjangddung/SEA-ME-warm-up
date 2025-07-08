
#include <bits/stdc++.h>
#include "Car.h"
#include "Sports.h"



Sports::Sports(const Car &car,int speed): Car(car) {
    this-> top_speed = new int(speed);
    std::cout << "-----Sports_Constructor----------\n";

}

Sports::~Sports(){
    delete top_speed ;
    std::cout << "-----Sports_Destructor----------\n";
}

Sports::Sports(const Sports&other) : Car(other) {
    //delete top_speed ;
    top_speed = new int(*other.top_speed);

    std::cout << "-----Sports_copy ----------\n";
}

Sports& Sports::operator = (const Sports& other){
    if (this != &other){
        Car::operator=(other);
        delete top_speed ;
        top_speed = new int(*other.top_speed);
    }

    std::cout << "-----Sports_copy operator----------\n";

    return *this ;
}

void Sports::sports_drive() const{
    drive();
    std::cout << "Top_speed : " << *top_speed << "\n";
}