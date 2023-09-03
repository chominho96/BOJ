#include <iostream>
#include <utility>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 5
#define endl '\n'

using namespace std;

struct fish {
    int row;
    int col;
    int dir;
    bool isExist;
};

int dx[]{ 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[]{ 0, 0, -1, -1, -1, 0, 1, 1, 1 };
fish FISH[17];
pair<int, int> MAP[MAX_SIZE][MAX_SIZE]; // <번호, 방향>, 번호 -1은 상어, 0은 빈칸
int ans = -1;

bool isRoute(const int& row, const int& col) {
    return row >= 0 && row < 4 && col >= 0 && col < 4;
}

int canMoveFish(int row, int col, int dir) {

    if (isRoute(row + dx[dir], col + dy[dir]) && MAP[row + dx[dir]][col + dy[dir]].first >= 0) {
        return dir;
    }

    for (int i = 0; i < 8; i++) {
        dir = (dir + 1) % 9;
        if (dir == 0) dir++;

        int next_row = row + dx[dir];
        int next_col = col + dy[dir];

        if (isRoute(next_row, next_col) && MAP[next_row][next_col].first >= 0) { // 갈 수 있으면
            return dir;
        }
    }

    return -1;
}

void swap(int row1, int col1, int row2, int col2) {
    int num1 = MAP[row1][col1].first;
    int second1 = MAP[row1][col1].second;
    bool existTemp1 = FISH[MAP[row1][col1].first].isExist;

    int num2 = MAP[row2][col2].first;
    int second2 = MAP[row2][col2].second;
    bool existTemp2 = FISH[MAP[row2][col2].first].isExist;

    MAP[row2][col2] = { num1, second1 };
    MAP[row1][col1] = { num2, second2 };
    if (num1 > 0) {
        FISH[num1] = { row2, col2, second1, existTemp1 };
    }
    if (num2 > 0) {
        FISH[num2] = { row1, col1, second2, existTemp2 };
    }
}

void moveFish() {
    for (int i = 1; i <= 16; i++) {

        int dir = canMoveFish(FISH[i].row, FISH[i].col, FISH[i].dir);

        if (FISH[i].isExist && dir != -1) {
            FISH[i].dir = dir;
            MAP[FISH[i].row][FISH[i].col].second = dir;
            int next_row = FISH[i].row + dx[FISH[i].dir];
            int next_col = FISH[i].col + dy[FISH[i].dir];
            swap(FISH[i].row, FISH[i].col, next_row, next_col);
        }
    }
}

void dfs(const int& row, const int& col, int value) {

    fish TEMP_FISH[17];
    pair<int, int> TEMP_MAP[MAX_SIZE][MAX_SIZE];
    for (int i = 1; i <= 16; i++) {
        TEMP_FISH[i] = { FISH[i].row, FISH[i].col, FISH[i].dir, FISH[i].isExist };
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            TEMP_MAP[i][j] = { MAP[i][j].first, MAP[i][j].second };
        }
    }

    if (value > ans) {
        ans = value;
    }

    FISH[MAP[row][col].first].isExist = false;
    MAP[row][col].first = -1;

    moveFish();

    int next_row = row + dx[MAP[row][col].second];
    int next_col = col + dy[MAP[row][col].second];

    while (true) {
        if (!isRoute(next_row, next_col)) break;

        if (MAP[next_row][next_col].first > 0) {
            MAP[row][col].first = 0;

            dfs(next_row, next_col, value + MAP[next_row][next_col].first);
        }

        next_row += dx[MAP[row][col].second];
        next_col += dy[MAP[row][col].second];
    }

    for (int i = 1; i <= 16; i++) {
        FISH[i] = { TEMP_FISH[i].row, TEMP_FISH[i].col, TEMP_FISH[i].dir, TEMP_FISH[i].isExist };
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            MAP[i][j] = { TEMP_MAP[i][j].first, TEMP_MAP[i][j].second };
        }
    }
}


int main() {
    FASTIO;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> MAP[i][j].first >> MAP[i][j].second;
            FISH[MAP[i][j].first] = { i, j, MAP[i][j].second, true };
        }
    }

    dfs(0, 0, MAP[0][0].first);
    cout << ans << endl;
}
