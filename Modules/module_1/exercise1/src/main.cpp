
#include <bits/stdc++.h>
#include "Car.h"
#include "Sports.h"


using namespace std;


int main(){
    string make;
    string model;
    int year;
    
    cout << "MaKe : " ;
    cin >> make ;
    cout << "model : ";
    cin >> model;
    cout << "year : ";
    cin >> year;
    Car car(make,model,year);
    Sports sp_car(car,100);
    sp_car.sports_drive();
    Sports new_car = sp_car ;
    cout << "new_Car \n";
    new_car.sports_drive();


    return 0 ;
}
