#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
    FASTIO;
    int C; cin >> C;

    for (int i = 0; i < C; i++) {
        int l, w; cin >> l >> w;
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < l; k++) cout << 'X';
            cout << endl;
        }
        if (i < C - 1) cout << endl;
    }
}