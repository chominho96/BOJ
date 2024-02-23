#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 100010
#define INF 987654321

using namespace std;

int DP[MAX_SIZE][5][5];
int STEP[MAX_SIZE];
int N = 0;
int SCORE[5][5];

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                DP[i][j][k] = INF;
            }
        }
    }
    for (int i = 0; i < 5; i++) {
        SCORE[0][i] = 2;
        SCORE[i][0] = 2;
    }
    SCORE[1][2] = 3;
    SCORE[2][3] = 3;
    SCORE[3][4] = 3;
    SCORE[4][1] = 3;
    SCORE[2][1] = 3;
    SCORE[3][2] = 3;
    SCORE[4][3] = 3;
    SCORE[1][4] = 3;

    SCORE[1][3] = 4;
    SCORE[3][1] = 4;
    SCORE[2][4] = 4;
    SCORE[4][2] = 4;

    for (int i = 0; i < 5; i++) {
        SCORE[i][i] = 1;
    }
}

void dp() {
    DP[1][STEP[1]][0] = 2;
    DP[1][0][STEP[1]] = 2;

    for (int i = 1; i < N; i++) {
        // i번째 step
        for (int l = 0; l < 5; l++) {
            for (int r = 0; r < 5; r++) {
                if (r != STEP[i + 1]) DP[i + 1][STEP[i + 1]][r] = min(DP[i + 1][STEP[i + 1]][r], DP[i][l][r] + SCORE[l][STEP[i + 1]]);
                if (l != STEP[i + 1]) DP[i + 1][l][STEP[i + 1]] = min(DP[i + 1][l][STEP[i + 1]], DP[i][l][r] + SCORE[STEP[i + 1]][r]);
            }
        }
    }
}

int ans() {
    if (N == 0) return 0;
    int ans = INF;
    for (int i = 0; i <= 4; i++) {
        ans = min(ans, DP[N][STEP[N]][i]);
        ans = min(ans, DP[N][i][STEP[N]]);
    }
    return ans;
}

int main() {
    FASTIO
    init();
    while (true) {
        cin >> STEP[++N];
        if (STEP[N] == 0) {
            N--;
            break;
        }
    }
    dp();
    cout << ans() << endl;
}