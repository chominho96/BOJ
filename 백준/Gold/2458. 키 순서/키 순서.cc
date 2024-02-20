#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 510
#define INF 987654321

using namespace std;

int N, M;
int MAP[MAX_SIZE][MAX_SIZE];
int RESULT[MAX_SIZE];

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for(int j = 0; j < MAX_SIZE; j++) {
            if (i == j) MAP[i][j] = 0;
            else MAP[i][j] = INF;
        }
    }
}

void floyd() {
    for (int i = 1; i <= N; i++) {
        // i를 거쳐갈 수 있는 방법이 있는지
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                MAP[j][k] = min(MAP[j][k], MAP[j][i] + MAP[i][k]);
            }
        }
    }
}

int ans() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        bool success = true;
        for (int j = 1; j <= N; j++) {
            if (MAP[i][j] == INF && MAP[j][i] == INF) {
                success = false;
                break;
            }
        }
        if (success) ans++;
    }
    return ans;
}

int main() {
    FASTIO
    cin >> N >> M;
    init();
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        MAP[a][b] = 1;
    }
    floyd();
    cout << ans() << endl;
}