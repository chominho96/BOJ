#include <iostream>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 31

using namespace std;

int N, M, H;
bool CONNECTED[MAX_SIZE][MAX_SIZE][MAX_SIZE];  // CONNECTED[i][j][k]는 i와 j가 k번째에서 연결되어 있는지 여부를 의미함
bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int ans = -1;

bool moveDown(int col) {

    int current_row = 1;
    int current_col = col;
    while (true) {

        if (current_col != 0 &&
            CONNECTED[current_col - 1][current_col][current_row]) {
            current_col--;
        } else if (current_col != N &&
                   CONNECTED[current_col][current_col + 1][current_row]) {
            current_col++;
        }

        if (current_row == H && current_col == col) return true;
        else if (current_row == H) return false;

        current_row++;
    }
}

bool totalMove() {

    for (int i = 1; i <= N; i++) {
        if (!moveDown(i)) return false;
    }
    return true;
}

void calc(int row, int col, int cnt) {

    if (cnt > 3) return;
    if (ans != -1 && cnt > ans) return;

    // 가로선을 만들 수 있는지 체크
    if (CONNECTED[col][col + 1][row]
        || (col != 0 && CONNECTED[col - 1][col][row])
        || (col != N - 1 && CONNECTED[col + 1][col + 2][row])) {
        return;
    }

    // 가로선 만들기
    CONNECTED[col][col + 1][row] = true;

    // 계산
    if (totalMove()) ans = cnt;

    // 다음으로 진행
    for (int i = col + 1; i < N; i++) {
        calc(row, i, cnt + 1);
    }
    for (int i = row + 1; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            calc(i, j, cnt + 1);
        }
    }

    // 가로선 없애기
    CONNECTED[col][col + 1][row] = false;
}

int main() {
    FASTIO;
    cin >> N >> M >> H;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        CONNECTED[b][b + 1][a] = true;
    }

    if (totalMove()) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j < N; j++) {
            calc(i, j, 1);
        }
    }

    cout << ans << endl;
}