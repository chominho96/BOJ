#include <iostream>

using namespace std;

int calc(int num) {
    int result = 0;
    for (int i = 1; i <= num; i++) {
        result += i;
    }
    return result;
}

int main() {
    while (true) {
        int N; cin >> N;
        if (N == 0) break;
        
        cout << calc(N) << '\n';
    }
}