#include <iostream>

using namespace std;

int main() {
    while (true) {
        int A, B; cin >> A >> B;
        if (A == 0 && B == 0) break;
        
        if (A > B) cout << "Yes\n";
        else cout << "No\n";
    }
}