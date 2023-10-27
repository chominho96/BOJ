#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }
    long long ans = 1;
    for (int i = N; i >= 1; i--) {
        ans *= i;
    }
    cout << ans << endl;
}