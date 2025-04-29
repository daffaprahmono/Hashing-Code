#include <iostream>
#include <fstream>
#include <ctime>
#include "sha256.h"

int main() {
    std::string sensorData = "Flow:2.6L/min";
    
    time_t timestamp = time(nullptr);
    std::string fullData = sensorData + "|" + std::to_string(timestamp);

    std::string hash = SHA256::hash(fullData);

    std::ofstream out("data_kirim.txt");
    out << fullData << "\n" << hash << std::endl;
    out.close();

    std::cout << "[Client] Data dan hash berhasil dikirim (disimpan ke file).\n";
    return 0;
}