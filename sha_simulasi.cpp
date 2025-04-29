#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <string>
#include <cstring>

// SHA-256 Implementation (ringan, header-only)
#include "sha256.h" // => kamu akan buat file ini nanti

using namespace std;

// Fungsi untuk ambil timestamp
string getCurrentTimestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    stringstream ss;
    ss << 1900 + ltm->tm_year
       << setw(2) << setfill('0') << 1 + ltm->tm_mon
       << setw(2) << setfill('0') << ltm->tm_mday
       << setw(2) << setfill('0') << ltm->tm_hour
       << setw(2) << setfill('0') << ltm->tm_min;

    return ss.str(); // Format: yyyymmddHHMM
}

int main() {
    float flow_rate = 120.5;

    string timestamp = getCurrentTimestamp();

    // Buat data yang akan dikirim
    stringstream data_stream;
    data_stream << "flow_rate=" << flow_rate << "&timestamp=" << timestamp;
    string data = data_stream.str();

    // Hitung hash-nya
    string hash = sha256(data);

    // Format akhir data kirim
    string final_payload = data + ";" + hash;

    cout << "Data yang dikirim: " << final_payload << endl;

    return 0;
}