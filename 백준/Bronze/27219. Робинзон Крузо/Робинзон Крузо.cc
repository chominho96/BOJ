#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    while (true) {
        if (n >= 5) {
            cout << 'V';
            n -= 5;
        } else {
            for (int i = 0; i < n; i++) {
                cout << 'I';
            }
            break;
        }
    }
    cout << '\n';
}