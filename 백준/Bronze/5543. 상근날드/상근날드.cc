#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, d, e; cin >> a >> b >> c >> d >> e; cout << min(a + d - 50, min(a + e - 50, min(b + d - 50, min(b + e - 50, min(c + d - 50, c + e - 50))))) << '\n';
}