#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
    FASTIO
    int M, K; cin >> M >> K;
    if (M % K == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}