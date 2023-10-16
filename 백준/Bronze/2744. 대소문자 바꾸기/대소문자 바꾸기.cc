#include <iostream>

using namespace std;

int main() {
    string input; cin >> input;
    string ans;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            ans += 'A' + (input[i] - 'a');
        }
        else {
            ans += 'a' + (input[i] - 'A');
        }
    }
    cout << ans << endl;
}