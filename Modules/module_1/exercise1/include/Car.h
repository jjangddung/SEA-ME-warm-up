#pragma once
#include <bits/stdc++.h>


class Car{
    private:
        std::string make;
        std::string model;
        int* year;

    public :
        Car(const std::string & make , const std::string& model,int year);
        ~Car();
        Car(const Car&other);
        Car& operator = (const Car& other);

        void drive() const;


};