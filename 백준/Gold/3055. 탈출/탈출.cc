#include <iostream>
#include <queue>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 100
#define MAX_DEPTH 3000

using namespace std;

struct NODE {
    pair<int, int> pos;
    int value;
};

int R, C;
char MAP[MAX_SIZE][MAX_SIZE][MAX_DEPTH];
bool visited[MAX_SIZE][MAX_SIZE][MAX_DEPTH];
int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };
pair<int, int> START;

bool isRoute(const int& row, const int& col) {
    return row >= 1 && row <= R && col >= 1 && col <= C;
}

void flood(int idx) {
    if (idx > 3000) return;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (MAP[i][j][idx] == '*') {
                for (int k = 0; k < 4; k++) {
                    int next_row = i + dx[k];
                    int next_col = j + dy[k];
                    if (isRoute(next_row, next_col)) {
                        if (MAP[next_row][next_col][idx] == '.' || MAP[next_row][next_col][idx] == 'S') {
                            MAP[next_row][next_col][idx + 1] = '*';
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (MAP[i][j][idx + 1] == 0) MAP[i][j][idx + 1] = MAP[i][j][idx];
        }
    }

    flood(idx + 1);
}

string bfs() {
    queue<NODE> que;
    que.push({START, 1});
    visited[START.first][START.second][1] = true;

    while (!que.empty()) {
        pair<int, int> current = que.front().pos;
        int idx = que.front().value;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int next_row = current.first + dx[i];
            int next_col = current.second + dy[i];

            if (isRoute(next_row, next_col) && !visited[next_row][next_col][idx + 1]) {
                visited[next_row][next_col][idx + 1] = true;
                if (MAP[next_row][next_col][idx + 1] == 'D') return to_string(idx);
                else if (MAP[next_row][next_col][idx + 1] == '.') {
                    que.push({ { next_row, next_col }, idx + 1 });
                }
            }
        }
    }
    return "KAKTUS";
}

int main() {
    FASTIO
    cin >> R >> C;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> MAP[i][j][1];
            if (MAP[i][j][1] == 'S') START = { i, j };
        }
    }

    flood(1);
    cout << bfs() << '\n';
}