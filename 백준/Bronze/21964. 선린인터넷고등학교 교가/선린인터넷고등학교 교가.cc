#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    string str; cin >> str;
    string result = "";
    for (int i = str.size() - 5; i < str.size(); i++) {
        result += str[i];
    }
    cout << result << '\n';
}