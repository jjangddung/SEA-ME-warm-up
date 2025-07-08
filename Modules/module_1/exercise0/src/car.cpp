#pragma once 
#include <bits/stdc++.h>
#include "../include/car.h"



//this는 객체를 가르킴
Car::Car(const std::string& name , int speed) : name(name){
    this->speed = new int(speed);
}

Car::~Car(){
    delete speed;
}

Car::Car(const Car&other) : name(other.name) {
    speed = new int(*other.speed);
    //speed를 동적 메모리로 할당함
}

Car& Car::operator = (const Car& other){
    if (this != &other){
        name = other.name ;
        delete speed ; //삭제를 안하면 메모리 누수가 발생한다.
                       // 사용하지 않는 메모리가 계속 차지가됨/
                       // python에서는 자동으로 관리가 됨.
        speed = new int(*other.speed);

    }

    return *this ;
}

void Car::print() const{
    cout << "Car_name : " << name  << "\n";
    cout << "Speed : " << *speed << " km/h";
}