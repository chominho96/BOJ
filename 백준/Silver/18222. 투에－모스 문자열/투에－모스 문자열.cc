#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

long long k;

int calc() {
    bool flipped = false;
    while (true) {
        if (k <= 2) break;
        long long two = 1;
        while (true) {
            if (two * 2 >= k) break;
            two *= 2;
        }
        k -= two;
        flipped = !flipped;
    }
    if (k == 2) return flipped ? 0 : 1;
    else return flipped ? 1 : 0;
}

int main() {
    FASTIO
    cin >> k;
    cout << calc() << endl;
}