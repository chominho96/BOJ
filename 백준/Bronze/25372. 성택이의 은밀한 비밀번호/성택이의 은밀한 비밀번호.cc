#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    while(N--) {
        string input; cin >> input;
        if (input.size() >= 6 && input.size() <= 9) cout << "yes\n";
        else cout << "no\n";
    }
}