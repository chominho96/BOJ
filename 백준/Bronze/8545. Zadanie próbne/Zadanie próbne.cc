#include <iostream>

using namespace std;

int main() {
    string str; cin >> str;
    for (int i = str.size() - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << '\n';
}