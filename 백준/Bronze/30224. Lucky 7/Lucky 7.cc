#include <iostream>

using namespace std;

int main() {
    string N; cin >> N;
    int num = stoi(N);
    bool isContain7 = false;
    for (int i = 0; i < N.size(); i++) {
        if (N[i] == '7') {
            isContain7 = true;
            break;
        }
    }
    if (!isContain7 && num % 7 != 0) cout << "0\n";
    else if (!isContain7 && num % 7 == 0) cout << "1\n";
    else if (isContain7 && num % 7 == 0) cout << "3\n";
    else if (isContain7) cout << "2\n";
}