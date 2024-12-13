#ifndef DRONE_CPP
#define DRONE_CPP

#include <iostream>
#include <fstream>
#include <string>

class Drone { //드론 추상 클래스
public:
    enum DroneType { DELIVERY, TAXI }; // 드론의 유형 (배송, 택시)

    // 생성자: 드론 ID, 유형, 속도, 고도를 초기화
    Drone(std::string id, DroneType type, double speed, double altitude)
        : id(id), type(type), speed(speed), altitude(altitude) {}

    // 가상 함수: 각 드론 유형의 작업 구현 (다형성 구현)
    virtual void performTask() const = 0; // 순수 가상 함수 (추상 클래스)

    // 드론의 기본 정보 출력(실제로는 사용하지 않음- 나중에 쓸 일이 있을 것 같아 일단 만들어 둠)
    void displayInfo() const {
        std::cout << "Drone ID: " << id << "\n"
                  << "Type: " << (type == DELIVERY ? "Delivery" : "Taxi") << "\n"
                  << "Speed: " << speed << " km/h\n"
                  << "Altitude: " << altitude << " m\n";
    }

    // 드론 이동 (함수 중복 구현)
    void flyTo(char zone) {
        std::cout << "드론 " << id << " 이 " << zone << "로 이동하겠습니다.\n";
    }

    void flyTo(double latitude, double longitude) { // 좌표를 사용해 드론이 이동하는 경우(사용 안함)
        std::cout << "드론 " << id << " 이 해당 좌표로 이동중입니다.: ("
                  << latitude << ", " << longitude << ")\n";
    }

    // 드론 ID 반환 (유틸리티 함수에서 사용)
    std::string getId() const {
        return id;
    }

    // 소멸자
    virtual ~Drone() {}

protected:
    std::string id;        // 드론 ID
    DroneType type;        // 드론 유형
    double speed;          // 비행 속도 
    double altitude;       // 현재 고도 
};

void logDroneMovement(const std::string& droneID, char zone) {
    std::ofstream logFile("drone_log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << "드론 " << droneID << "이 " << zone << "으로 이동했습니다.\n";
        logFile.close();
    } else {
        std::cerr << "로그 파일을 열람할 수 없습니다.\n";
    }
}

#endif
