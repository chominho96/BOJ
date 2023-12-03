#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

int main() {
    auto now = chrono::system_clock::now();
    
    time_t now_c = chrono::system_clock::to_time_t(now);
    struct tm* utc_tm = gmtime(&now_c);

    cout << (utc_tm->tm_year + 1900) << '\n';
    cout << (utc_tm->tm_mon + 1) << '\n';
    cout << utc_tm->tm_mday << '\n';

    return 0;
}
