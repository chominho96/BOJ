#include <iostream>

using namespace std;

int main() {
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        string s; cin >> s;
        for (int j = 0; j < 8; j++) {
            if (s[j] == 'P') ans++;
            else if (s[j] == 'N') ans += 3;
            else if (s[j] == 'B') ans += 3;
            else if (s[j] == 'R') ans += 5;
            else if (s[j] == 'Q') ans += 9;
            else if (s[j] == 'p') ans--;
            else if (s[j] == 'n') ans -= 3;
            else if (s[j] == 'b') ans -= 3;
            else if (s[j] == 'r') ans -= 5;
            else if (s[j] == 'q') ans -= 9;
        }
    }
    cout << ans << '\n';
}