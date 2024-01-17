#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        int num; cin >> num;
        ans += num;
    }
    if (ans == 0) cout << "Stay\n";
    if (ans > 0) cout << "Right\n";
    if (ans < 0) cout << "Left\n";
}