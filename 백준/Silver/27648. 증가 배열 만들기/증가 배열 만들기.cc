#include <iostream>
#include <utility>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 1001

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
int dx[]{0, 1};
int dy[]{1, 0};
int N, M, K;

bool isRoute(const int& row, const int& col) {
    return row >= 1 && row <= N && col >= 1 && col <= M;
}

void bfs() {
    queue<pair<int, int>> que;
    que.push({1, 1});
    MAP[1][1] = 1;

    while (!que.empty()) {
        int row = que.front().first;
        int col = que.front().second;
        que.pop();
        for (int i = 0; i < 2; i++) {
            int n_row = row + dx[i];
            int n_col = col + dy[i];

            if (isRoute(n_row, n_col)) {
                if (MAP[n_row][n_col] < MAP[row][col]) {
                    MAP[n_row][n_col] = MAP[row][col] + 1;
                    if (MAP[n_row][n_col] > K) {
                        cout << "NO" << endl;
                        exit(0);
                    }
                    que.push({n_row, n_col});
                }
            }
        }
    }
}

void print() {
    cout << "YES" << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << MAP[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    FASTIO
    cin >> N >> M >> K;
    bfs();
    print();
}