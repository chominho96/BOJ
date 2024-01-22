#include <iostream>

using namespace std;

int main() {
    int a, b; cin >> a >> b; a *= b;
    int c1, c2, c3, c4, c5; cin >> c1 >> c2 >> c3 >> c4 >> c5;
    cout << c1 - a << ' ' << c2 - a << ' ' << c3 - a << ' ' << c4 - a << ' ' << c5 - a << '\n';
}