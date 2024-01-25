#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    while (N--) {
        int X, Y; cin >> X >> Y;
        if (X >= Y) cout << "MMM BRAINS\n";
        else cout << "NO BRAINS\n";
    }
}