#include <iostream>

using namespace std;

int main() {
    int a, b; cin >> a >> b; 
    if ((a + b) % 2 != 0) cout << "-1\n";
    else if (a - ((a + b) / 2) < 0) cout << "-1\n";
    else cout << (a + b) / 2 << ' ' << a - ((a + b) / 2) << '\n';
}