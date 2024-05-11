#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int ans = 1;
    for (int i = 1; i <= n; ans *= i, ans %= 10, i++);
    cout << ans << '\n';
}