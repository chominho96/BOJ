#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    time_t t = time(nullptr);
    tm local_time = *localtime(&t);
    local_time.tm_hour += 9;
    if (local_time.tm_hour >= 24) {
        local_time.tm_hour -= 24;
    }

    cout << put_time(&local_time, "%Y-%m-%d") << '\n';
}
