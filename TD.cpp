#ifndef TAXI_DELIVERY_DRONE_CPP
#define TAXI_DELIVERY_DRONE_CPP

#include "Drone.cpp"
#include <iostream>

// TaxiDrone 클래스: Drone 클래스 상속
class TaxiDrone : public Drone {
public:
    // 생성자
    TaxiDrone(std::string id, double speed, double altitude)
        : Drone(id, Drone::TAXI, speed, altitude) {}

    // 가상 함수 구현: 택시 작업 수행
    void performTask() const override {
        std::cout << "Taxi Drone " << id << " 이 택시 운행 중입니다.\n";
    }
};

// DeliveryDrone 클래스: Drone 클래스 상속
class DeliveryDrone : public Drone {
public:
    // 생성자
    DeliveryDrone(std::string id, double speed, double altitude)
        : Drone(id, Drone::DELIVERY, speed, altitude) {}

    // 가상 함수 구현: 배송 작업 수행
    void performTask() const override {
        std::cout << "Delivery Drone " << id << " 이 물품을 배송 중입니다.\n";
    }
};

#endif
