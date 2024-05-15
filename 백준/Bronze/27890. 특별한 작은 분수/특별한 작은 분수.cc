#include <iostream>

using namespace std;

int main() {
    int x, N; cin >> x >> N;
    while (N--) {
        if (x % 2 == 0) x /= 2;
        else x *= 2;
        x ^= 6;
    }
    cout << x << '\n';
}