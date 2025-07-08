# pragma once 
#include <bits/stdc++.h>

using namespace std;




class Car {
    private :
        std::string name ; // string 자체가 내부적으로 동적 메모리 할당임 
                      // 굳이 포인터를 사용할 필요가 없음

        int* speed ;  // new를 사용해서 동적 메모리 할당을 위해서는 
                      // pointer를 사용해야함.

    public :
        Car(const std::string& name = "Default", int speed = 0);  //생성자
        ~Car(); //소멸자
        Car(const Car&other); //복사 생성자 -> 새 객체를 만들 때임
        Car& operator=(const Car& other); // 복사 대입 연산자 -> 기존 객체에 복사를 할때 사용
                                          // 그니깐 미리 만들어진 객체에 값을 넣는거임

                                          //반환 type이 Car&임
        void print() const ;// const를 사용함으로써 읽기전용으로만
};