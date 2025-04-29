#include <iostream>
#include <fstream>
#include <string>
#include "sha256.h"

int main() {
    std::ifstream in("data_kirim.txt");
    std::string fullData, receivedHash;

    std::getline(in, fullData);
    std::getline(in, receivedHash);
    in.close();

    std::string calculatedHash = SHA256::hash(fullData);

    std::cout << "[Server] Data diterima: " << fullData << std::endl;
    std::cout << "[Server] Hash diterima: " << receivedHash << std::endl;
    std::cout << "[Server] Hash dihitung: " << calculatedHash << std::endl;

    if (calculatedHash == receivedHash) {
        std::cout << "[Server] Data valid, tidak terjadi perubahan.\n";
    } else {
        std::cout << "[Server] Data rusak atau telah dimodifikasi!\n";
    }

    return 0;
}