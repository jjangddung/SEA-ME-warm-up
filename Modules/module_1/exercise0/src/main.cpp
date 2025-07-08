#include <bits/stdc++.h>
#include "../include/car.h"
#pragma once 


using namespace std;




int main(){
    string name ;
    int speed ;
    cout << "input name:";
    cin >> name;
    cout << "\n input speed: ";
    cin >> speed;
    Car mycar(name,speed);
    mycar.print();



    return 0 ;
}