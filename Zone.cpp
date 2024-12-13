#ifndef ZONE_CPP
#define ZONE_CPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>

// Zone 클래스: 구역 관리
// - 구역 상태를 관리하고 드론의 접근 가능 여부를 확인
class Zone {
public:
    // 생성자: 초기 구역 상태 설정
    Zone() {
        zones["A"] = "EMPTY";
        zones["B"] = "EMPTY";
        zones["C"] = "EMPTY";
        zones["D"] = "이용 중";
    }

    // 특정 구역의 상태 확인
    bool isZoneAvailable(char zone) const {
        std::string zoneKey(1, zone);
        if (zones.find(zoneKey) != zones.end()) {
            return zones.at(zoneKey) == "EMPTY";
        }
        std::cout << "Invalid zone selected.\n"; //EMPTY가 아니면 이동 불가!
        return false;
    }

    // 특정 구역의 상태 변경
    void setZoneStatus(char zone, const std::string& status) {
        std::string zoneKey(1, zone);
        if (zones.find(zoneKey) != zones.end()) {
            zones[zoneKey] = status;
            logZoneChange(zoneKey, status);
        } else {
            std::cout << "불가능한 구역 선택.\n";
        }
    }

    // 구역 상태 출력
    void displayZoneStatus() const {
        for (const auto& zone : zones) {
            std::cout << "구역 " << zone.first << ": " << zone.second << "\n";
        }
    }

private:
    std::map<std::string, std::string> zones; // 각 구역 상태를 저장

    // 구역 상태 변경 로그 기록
    void logZoneChange(const std::string& zone, const std::string& newState) {
        std::ofstream logFile("zone_log.txt", std::ios::app); //zone_log.txt파일을 생성하여 비행 구역 변경점을 기록.
        if (logFile.is_open()) {
            logFile << "구역" << zone << " 가 " << newState << "으로 변경되었습니다.\n";
            logFile.close();
        } else {
            std::cerr << "Unable to open log file.\n";
        }
    }
};

#endif
