//드론 운항 시스템 구현을 목표로 코드를 작성했습니다.
//Drone.cpp 택시, 물류 드론 2가지를 만들 때 사용되는 Drone 추상 클래스가 구현되어있습니다.
//Zone.cpp에선 구역 상태를 초기화 하고 드론 이동에 따른 구역 상태를 변경합니다. 또한 구역이 어떻게 변경되었는지 로그를 남깁니다.
//TD.cpp에서 Drone 클래스를 상속받아 2가지의 다른 드론을 제작합니다.


#include <iostream>
#include <memory>
#include <stdexcept>
#include "Drone.cpp"
#include "Zone.cpp"
#include "U.cpp"
#include "TD.cpp"

// 드론 생성 함수
std::unique_ptr<Drone> createDrone(const std::string& droneId) {
    if (droneId[0] == 'T' || droneId[0] == 't') {
        std::cout << "택시 드론 생성중~\n";
        return std::unique_ptr<TaxiDrone>(new TaxiDrone(droneId, 50.0, 100.0));
    } else if (droneId[0] == 'D' || droneId[0] == 'd') {
        std::cout << "배송 드론 생성중~\n";
        return std::unique_ptr<DeliveryDrone>(new DeliveryDrone(droneId, 30.0, 120.0));
    } else {
        throw std::invalid_argument("유효하지 않은 ID입니다. 반드시 'T' 또는 'D'로 시작해야 합니다."); //예외처리
    }
}

// 메인 함수
int main() {
    Zone zoneManager;
    std::unique_ptr<Drone> drone;
    std::string droneId;
    bool droneCreated = false;
    // 드론 생성 루프
    while (!droneCreated) {
        try { //예외처리 try
            std::cout << "드론 ID를 입력하세요. (예시) T1 for Taxi, D1 for Delivery): ";
            std::cin >> droneId;
            drone = createDrone(droneId); // 예외 발생 가능
            droneCreated = true; // 드론 생성 성공
        } catch (const std::invalid_argument& e) { //예외 발생시 재입력 받음.
            std::cerr << e.what() << "\n다시 입력해주세요.\n";
        }
    }

    char userChoice;
    bool running = true;

    while (running) {
        zoneManager.displayZoneStatus(); // 현재 구역 상태 출력
        try {
            std::cout << "\n어디로 가시겠습니까? (A, B, C, D, or E to exit): ";
            std::cin >> userChoice;

            if (userChoice == 'E' || userChoice == 'e') {
                running = false;
                std::cout << "이용해주셔서 감사합니다!\n";
            } else if (userChoice >= 'A' && userChoice <= 'D') {
                if (zoneManager.isZoneAvailable(userChoice)) {
                    drone->flyTo(userChoice); // 다형성을 활용하여 드론 이동
                    drone->performTask();    // 드론 작업 수행
                    logDroneMovement(droneId, userChoice); //드론 이동기록 로그 출력
                    zoneManager.setZoneStatus(userChoice, "이용 중");
                } else {
                    throw std::runtime_error("현재 해당 지역이 사용 중입니다. 다른 지역을 이용해주세요.");
                }
            } else {
                throw std::invalid_argument("잘못된 입력입니다. A, B, C, D, 구역 선택 또는 E로 나가주세요.");
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "입력 오류: " << e.what() << "\n";
        } catch (const std::runtime_error& e) {
            std::cerr << "구역 오류: " << e.what() << "\n";
        }
    }

    return 0;
}
