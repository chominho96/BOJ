#include <iostream>

using namespace std;

int main() {
    int a, b; cin >> a >> b;
    if (a <= 3) cout << b - a << '\n';
    else cout << b + (24 - a) << '\n';
}