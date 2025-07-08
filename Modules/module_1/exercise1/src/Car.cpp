
#include <bits/stdc++.h>
#include "Car.h"



// :: class Car에 있는 함수임을 나타냄
Car::Car(const std::string& make, const std::string& model, int year) 
    : make(make), model(model){
        this->year = new int(year);
        std::cout << "------Car_Constructor--------\n";
    }
Car::~Car(){
    std::cout << "------Car_Destructor--------\n";
    delete year;
}

Car::Car(const Car&other)
    : make(other.make), model(other.model){
        //delete year;
        std::cout << "------Car_Copy Constructor--------\n";
        year = new int(*other.year); //pointer가 실제로 가르키는 값
    }

Car& Car::operator  =(const Car& other){
    if (this != &other){
        make = other.make;
        model = other.model;

        delete year;
        year= new int(*other.year);
        std::cout << "------Car_Copy assignment operator override--------\n";
    }

    return *this; //자기 자신 반환
}

void Car::drive() const{
    std::cout << "Make: " << make << "\n";
    std::cout << "Model: " << model << "\n";
    std::cout << "Year: " << *year << "\n";
}

