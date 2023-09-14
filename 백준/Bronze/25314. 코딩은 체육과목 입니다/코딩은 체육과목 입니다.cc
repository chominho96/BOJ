#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

using namespace std;

int main() {
    FASTIO;
    int N; cin >> N;
    while (true) {
        if (N <= 0) break;
        cout << "long ";
        N -= 4;
    }
    cout << "int" << endl;
}