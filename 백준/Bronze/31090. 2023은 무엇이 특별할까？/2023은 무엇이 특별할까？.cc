#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    while (N--) {
        int t; cin >> t;
        int div = t % 100;
        if ((t + 1) % div == 0) cout << "Good\n";
        else cout << "Bye\n";
    }
}