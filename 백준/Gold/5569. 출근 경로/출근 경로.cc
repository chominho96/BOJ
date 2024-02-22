#include <iostream>
#include <utility>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define DIVIDEND 100000
#define MAX_SIZE 101

using namespace std;

int W, H;
int ans = 0;
int dx[]{-1, 0};
int dy[]{0, -1};
int DP[MAX_SIZE][MAX_SIZE][2][2];
// dir: 0은 옆 1은 위
// [w][h][dir][cnt]

bool isRoute(const int &w, const int &h) {
    return w >= 1 && w <= W && h >= 1 && h <= H;
}

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            DP[i][j][0][0] = -1;
            DP[i][j][0][1] = -1;
            DP[i][j][1][0] = -1;
            DP[i][j][1][1] = -1;
        }
    }
}

int dp(int w, int h, int dir, int cnt) {
    if (!isRoute(w, h)) return 0;
    if (w == 1 && dir == 0) return 0;
    if (h == 1 && dir == 1) return 0;
    if (DP[w][h][dir][cnt] != -1) return DP[w][h][dir][cnt];
    if (w == 1 && h == 2) {
        if (dir == 1 && cnt == 0) return 1;
        return 0;
    }
    if (w == 2 && h == 1) {
        if (dir == 0 && cnt == 0) return 1;
        return 0;
    }

    if (cnt == 0) {

        return DP[w][h][dir][cnt] =
                       (dp(w + dx[dir], h + dy[dir], dir, 0) % DIVIDEND +
                       dp(w + dx[dir], h + dy[dir], dir, 1) % DIVIDEND) % DIVIDEND;
    }

    else {
        return DP[w][h][dir][cnt] =
                       (dp(w + dx[dir], h + dy[dir], 1 - dir, 0)) % DIVIDEND;
    }
}

int main() {
    FASTIO
    cin >> W >> H;
    init();
    cout << (dp(W, H, 0, 0) % DIVIDEND + dp(W, H, 0, 1) % DIVIDEND + dp(W, H, 1, 0) % DIVIDEND + dp(W, H, 1, 1) % DIVIDEND) % DIVIDEND << endl;
}