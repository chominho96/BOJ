#include <iostream>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
    FASTIO
    int N; cin >> N;
    int D = 0; int P = 0;
    while (N--) {
        char c; cin >> c;
        if (abs(D - P) >= 2) continue;
        if (c == 'D') D++; else P++;
    }
    cout << D << ':' << P << endl;
}