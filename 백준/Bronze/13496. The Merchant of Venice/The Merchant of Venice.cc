#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
    FASTIO
    int n, s, d, t, ans;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> s >> d;
        ans = 0;
        for (int j = 0, a, b; j < n; j++) {
            cin >> a >> b;
            if (s * d >= a) ans += b;
        }
        cout << "Data Set " << i << ':' << endl << ans << endl << endl;
    }
}