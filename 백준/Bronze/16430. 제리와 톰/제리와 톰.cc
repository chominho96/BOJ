#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    
    a = b - a;
    while(true) {
        int g = gcd(a, b);
        if (g == 1) break;
        a /= g;
        b /= g;
        
    }
    
    cout << a << ' ' << b << '\n';
}