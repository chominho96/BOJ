#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

using namespace std;

int main() {
    FASTIO;
    int T; cin >> T;
    string str;
    while(T--) {
        cin >> str;
        cout << str[0] << str[str.size() - 1] << endl;
    }
}