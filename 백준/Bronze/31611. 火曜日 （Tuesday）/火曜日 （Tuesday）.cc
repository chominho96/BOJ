#include <iostream>

using namespace std;

int main() {
    int X; cin >> X; if (X == 0 || (X >= 2 && (X - 2) % 7 == 0)) cout << "1\n"; else cout << "0\n";
}