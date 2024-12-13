#ifndef UTILITY_CPP
#define UTILITY_CPP

#include <iostream>
#include <fstream>
#include <limits>

// // 유효한 구역 입력을 받는 함수
// char getValidZoneInput() {
//     char zone;
//     while (true) {
//         std::cout << "목적지를 선택해 주세요. (A, B, C, D, E to exit): ";
//         std::cin >> zone;

//         if (zone == 'A' || zone == 'B' || zone == 'C' || zone == 'D' || zone == 'E' || zone == 'e') {
//             return zone;
//         } else {
//             std::cout << "잘못된 입력입니다. A, B, C, D, or E(to exit) 중 하나를 선택해주세요.\n";
//             std::cin.clear(); // 잘못된 입력 클리어하기
//             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         }
//     }
// }

// 드론 이동 로그를 기록하는 함수
// void logDroneMovement(const std::string& droneID, char zone) {
//     std::ofstream logFile("drone_log.txt", std::ios::app);
//     if (logFile.is_open()) {
//         logFile << "드론 " << droneID << "이 " << zone << "으로 이동했습니다.\n";
//         logFile.close();
//     } else {
//         std::cerr << "로그 파일을 열람할 수 없습니다.\n";
//     }
// }

#endif
