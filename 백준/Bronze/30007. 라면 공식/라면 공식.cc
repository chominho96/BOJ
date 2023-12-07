#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    while(N--) {
        int A, B, X; cin >> A >> B >> X;
        cout << A * (X - 1) + B << '\n';
    }
}