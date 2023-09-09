#include <iostream>
#include <queue>
#include <utility>
#include <cmath>
#include <vector>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 51

using namespace std;

int N, L, R;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            visited[i][j] = false;
        }
    }
}

bool isRoute(const int &row, const int &col) {
    return row >= 1 && row <= N && col >= 1 && col <= N;
}

bool bfs(int row, int col) {

    queue<pair<int, int>> que;
    que.push({row, col});
    vector<pair<int, int>> vec;
    vec.push_back({row, col});
    int total = MAP[row][col];
    visited[row][col] = true;
    bool result = false;

    while (!que.empty()) {
        int current_row = que.front().first;
        int current_col = que.front().second;
        que.pop();

        for (int i = 0; i < 4; i++) {
            int next_row = current_row + dx[i];
            int next_col = current_col + dy[i];

            if (isRoute(next_row, next_col) &&
                !visited[next_row][next_col] &&
                (abs(MAP[current_row][current_col] - MAP[next_row][next_col]) >= L
                 && abs(MAP[current_row][current_col] - MAP[next_row][next_col]) <= R)) {

                result = true;
                total += MAP[next_row][next_col];
                visited[next_row][next_col] = true;

                que.push({next_row, next_col});
                vec.push_back({next_row, next_col});
            }
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        MAP[vec[i].first][vec[i].second] = total / vec.size();
    }

    return result;
}

int main() {
    FASTIO;
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
        }
    }

    int ans = 0;
    while (true) {
        bool isContinue = false;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (!visited[i][j]) {
                    if (!isContinue) isContinue = bfs(i, j);
                    else bfs(i, j);
                }
            }
        }
        if (!isContinue) break;
        ans++;
        init();
    }

    cout << ans << endl;
}