#ifndef SHA256_H
#define SHA256_H

#include <string>
#include <cstdint>

class SHA256 {
public:
    SHA256();
    void update(const std::string& data);
    std::string final();
    static std::string hash(const std::string& data); // Helper untuk langsung hashing

private:
    void reset();
    void transform();
    static uint32_t rotr(uint32_t x, uint32_t n);

    uint8_t data[64];
    uint32_t datalen;
    uint64_t bitlen;
    uint32_t state[8];

    static const uint32_t k[64];
};

#endif