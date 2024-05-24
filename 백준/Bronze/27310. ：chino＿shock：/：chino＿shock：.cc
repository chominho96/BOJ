#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str; cin >> str;
    cout << str.size() + count(str.begin(), str.end(), ':') + count(str.begin(), str.end(), '_') * 5 << '\n';
}