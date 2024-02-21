#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define DIVIDEND 10007
#define MAX_SIZE 1001

using namespace std;

long long DP[MAX_SIZE][MAX_SIZE];

long long dp(int i, int j) {
    if (DP[i][j] != 0) return DP[i][j];
    if (j == 0 || i == j) return DP[i][j] = 1;
    return DP[i][j] = (dp(i - 1, j) + dp(i - 1, j - 1)) % DIVIDEND;
}

void init() {
    for (int i = 1000; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            dp(i, j);
        }
    }
}

int main() {
    FASTIO
    init();
    int N, K; cin >> N >> K;
    cout << DP[N][K] << endl;
}