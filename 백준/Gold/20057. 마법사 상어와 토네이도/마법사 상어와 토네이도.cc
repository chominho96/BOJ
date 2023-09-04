#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 501

using namespace std;

struct move_ {
    int row;
    int col;
    double percentage;
};

int MAP[MAX_SIZE][MAX_SIZE];
int N;
vector<move_> MOVE[4];  // 0: 왼쪽, 1: 아래쪽, 2: 오른쪽, 3: 위쪽
int dx[]{0, 1, 0, -1};
int dy[]{-1, 0, 1, 0};

void init() {
    // 왼쪽
    MOVE[0].push_back({0, -2, 0.05});
    MOVE[0].push_back({-1, -1, 0.1});
    MOVE[0].push_back({1, -1, 0.1});
    MOVE[0].push_back({-1, 0, 0.07});
    MOVE[0].push_back({1, 0, 0.07});
    MOVE[0].push_back({-2, 0, 0.02});
    MOVE[0].push_back({2, 0, 0.02});
    MOVE[0].push_back({-1, 1, 0.01});
    MOVE[0].push_back({1, 1, 0.01});

    // 아럐쪽
    MOVE[1].push_back({2, 0, 0.05});
    MOVE[1].push_back({1, -1, 0.1});
    MOVE[1].push_back({1, 1, 0.1});
    MOVE[1].push_back({0, -1, 0.07});
    MOVE[1].push_back({0, 1, 0.07});
    MOVE[1].push_back({0, -2, 0.02});
    MOVE[1].push_back({0, 2, 0.02});
    MOVE[1].push_back({-1, -1, 0.01});
    MOVE[1].push_back({-1, 1, 0.01});

    // 오른쪽
    MOVE[2].push_back({0, 2, 0.05});
    MOVE[2].push_back({-1, 1, 0.1});
    MOVE[2].push_back({1, 1, 0.1});
    MOVE[2].push_back({-1, 0, 0.07});
    MOVE[2].push_back({1, 0, 0.07});
    MOVE[2].push_back({-2, 0, 0.02});
    MOVE[2].push_back({2, 0, 0.02});
    MOVE[2].push_back({-1, -1, 0.01});
    MOVE[2].push_back({1, -1, 0.01});

    // 위쪽
    MOVE[3].push_back({-2, 0, 0.05});
    MOVE[3].push_back({-1, -1, 0.1});
    MOVE[3].push_back({-1, 1, 0.1});
    MOVE[3].push_back({0, -1, 0.07});
    MOVE[3].push_back({0, 1, 0.07});
    MOVE[3].push_back({0, -2, 0.02});
    MOVE[3].push_back({0, 2, 0.02});
    MOVE[3].push_back({1, -1, 0.01});
    MOVE[3].push_back({1, 1, 0.01});
}

bool isRoute(const int& row, const int& col) {
    return row >= 1 && row <= N && col >= 1 && col <= N;
}

int move(const int& row, const int& col, const int& dir) {
    int ans = 0;
    int total = MAP[row][col];

    for (int i = 0; i < MOVE[dir].size(); i++) {
        int next_row = row + MOVE[dir][i].row;
        int next_col = col + MOVE[dir][i].col;
        int value = MAP[row][col] * MOVE[dir][i].percentage;

        if (isRoute(next_row, next_col)) {
            MAP[next_row][next_col] += value;
        }
        else {
            ans += value;
        }
        total -= value;
    }

    if (isRoute(row + dx[dir], col + dy[dir])) {
        MAP[row + dx[dir]][col + dy[dir]] += total;
    }
    else {
        ans += total;
    }

    MAP[row][col] = 0;
    return ans;
}

int calc() {
    int dir = 0;
    int ans = 0;

    int row = N / 2 + 1;
    int col = N / 2 + 1;

    int len = 1;
    int cnt = 0;

    while (true) {
        for (int i = 0; i < len; i++) {
            row += dx[dir];
            col += dy[dir];
            ans += move(row, col, dir);
            if (row == 1 && col == 1) break;
        }

        if (row == 1 && col == 1) break;

        dir = (dir + 1) % 4;
        if (++cnt == 2) {
            cnt = 0;
            len++;
        }
    }

    return ans;
}

int main() {
    FASTIO;
    init();
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> MAP[i][j];
        }
    }

    cout << calc() << endl;
}
