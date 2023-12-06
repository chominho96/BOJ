#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    if (N >= 620 && N <= 780) cout << "Red\n";
    if (N >= 590 && N < 620) cout << "Orange\n";
    if (N >= 570 && N < 590) cout << "Yellow\n";
    if (N >= 495 && N < 570) cout << "Green\n";
    if (N >= 450 && N < 495) cout << "Blue\n";
    if (N >= 425 && N < 450) cout << "Indigo\n";
    if (N >= 380 && N < 425) cout << "Violet\n";
}