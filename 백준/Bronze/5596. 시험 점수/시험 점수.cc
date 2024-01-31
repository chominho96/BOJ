#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a1, b1, c1, d1, a2, b2, c2, d2; cin >> a1 >> b1 >> c1 >> d1 >> a2 >> b2 >> c2 >> d2; cout << max(a1 + b1 + c1 + d1, a2 + b2 + c2 + d2) << '\n';
}