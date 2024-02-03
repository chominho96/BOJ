#include <iostream>

using namespace std;

int main() {
    string str; cin >> str;
    if (str.size() == 4) cout << 20 << '\n';
    else if (str.size() == 3) {
        if (str[0] == '1' && str[1] == '0') cout << 10 + int(str[2] - '0') << '\n';
        else cout << int(str[0] - '0') + 10 << '\n';
    }
    else {
        cout << int(str[0] - '0') + int(str[1] - '0') << '\n';
    }
}