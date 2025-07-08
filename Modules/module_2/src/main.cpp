#include <iostream>
#include "Car.h"

#include <memory>
#include <array>


int main(){
    

    auto engine = std::make_shared<Engine>("Turbo", 200);

    // 2. Transmission
    auto transmission = std::make_shared<Transmission>(1); // 1단

    // 3. Wheels
    std::array<std::shared_ptr<Wheel>, 4> wheels;
    for (auto& w : wheels) {
        w = std::make_shared<Wheel>(40);  // 속도 40으로 초기화
    }

    // 4. Brakes
    std::array<std::shared_ptr<Brake>, 4> brakes;
    for (auto& b : brakes) {
        b = std::make_shared<Brake>(false);  // 브레이크 비활성화
    }

    // 5. Car 생성
    Car car(engine, wheels, brakes, transmission);

    // 6. 사용
    car.prints_part();

    std::cout << "--------------------rotate----------------------------\n";

    car.turn_left();
    car.prints_part();  // 왼쪽 회전한 상태 출력


    std::cout << "----------------------brake---------------------------\n";

    car.stop();
    car.prints_part();

    return 0;





}