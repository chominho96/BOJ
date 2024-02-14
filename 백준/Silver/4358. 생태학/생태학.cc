#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

map<string, int> mp;
int tot = 0;

int main() {
    FASTIO cout << setprecision(4); cout << fixed;
    while (true) {
        string str; getline(cin, str);
        if (cin.eof()) break;
        tot++;
        if (mp.find(str) != mp.end()) mp[str]++;
        else mp[str] = 1;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << ' ' << (double)it->second / (double)tot * 100.0 << '\n';
    }
}