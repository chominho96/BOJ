#include <iostream>

using namespace std;

int NUM[7];

int main() {
    for (int i = 1; i <= 6; i++) {
        cin >> NUM[i];
    }
    cout << 1 - NUM[1] << ' ' << 1 - NUM[2] << ' ' << 2 - NUM[3] << ' ' << 2 - NUM[4] << ' ' << 2 - NUM[5] << ' ' << 8 - NUM[6] << endl;
}