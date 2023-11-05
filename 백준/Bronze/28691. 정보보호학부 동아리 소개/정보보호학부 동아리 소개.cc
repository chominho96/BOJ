#include <iostream>

using namespace std;

int main() {
    char t; cin >> t;
    if (t == 'M') cout << "MatKor\n";
    if (t == 'W') cout << "WiCys\n";
    if (t == 'C') cout << "CyKor\n";
    if (t == 'A') cout << "AlKor\n";
    if (t == '$') cout << "$clear\n";
}