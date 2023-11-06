#include <iostream>

using namespace std;

int NUM[9];

int main() {
    bool success = true;
    for (int i = 1; i <= 8; i++) {
        cin >> NUM[i];
        if (NUM[i] == 9) success = false;
    }
    if (success) cout << "S\n";
    else cout << "F\n";
}