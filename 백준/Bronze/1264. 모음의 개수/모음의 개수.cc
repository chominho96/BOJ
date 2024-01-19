#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int calc(string& str) {
    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') ans++;
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') ans++;
    }
    return ans;
}

int main() {
    FASTIO;
    while (true) {
        string str; getline(cin, str, '\n');
        if (str == "#") break;
        cout << calc(str) << '\n';
    }
}