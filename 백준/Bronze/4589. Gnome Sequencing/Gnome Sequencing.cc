#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    cout << "Gnomes:\n";
    while (N--) {
        int a, b, c; cin >> a >> b >> c;
        if (a <= b && b <= c) cout << "Ordered\n";
        else if (a >= b && b >= c) cout << "Ordered\n";
        else cout << "Unordered\n";
    }
}