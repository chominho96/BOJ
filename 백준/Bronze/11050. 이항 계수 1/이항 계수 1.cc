#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 12

using namespace std;

int N, K;
int DP[MAX_SIZE][MAX_SIZE];

int calc(int i, int j) {
    if (DP[i][j] != 0) return DP[i][j];
    if (j == 0 || i == j) return DP[i][j] = 1;
    return DP[i][j] = calc(i - 1, j) + calc(i - 1, j - 1);
}

void init() {
    for (int i = 10; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            calc(i, j);
        }
    }
}

int main() {
    FASTIO
    cin >> N >> K;
    init();
    cout << DP[N][K] << endl;
}