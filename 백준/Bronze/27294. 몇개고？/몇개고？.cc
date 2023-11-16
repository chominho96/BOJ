#include <iostream>

using namespace std;

int main() {
    int T, S; cin >> T >> S;
    
    if (S == 0 && T >= 12 && T <= 16) cout << "320\n";
    else cout << "280\n";
}