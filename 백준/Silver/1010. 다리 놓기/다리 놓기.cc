#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 31

using namespace std;

int N, M;
long long DP[MAX_SIZE][MAX_SIZE];

long long dp(int i, int j) {
    if (DP[i][j] != 0) return DP[i][j];
    if (j == 0 || i == j) return DP[i][j] = 1;
    return DP[i][j] = dp(i - 1, j) + dp(i - 1, j - 1);
}

void init() {
    for (int i = 30; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            dp(i, j);
        }
    }
}

int main() {
    FASTIO
    init();
    int T; cin >> T;
    while (T--) {
        cin >> N >> M;
        cout << DP[M][N] << endl;
    }
}