#include <iostream>
#include <string>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
    FASTIO
    int N; cin >> N;
    while (N--) {
        string s; cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                cout << char('a' + (s[i] - 'A'));
            }
            else {
                cout << s[i];
            }
        }
        cout << endl;
    }
}