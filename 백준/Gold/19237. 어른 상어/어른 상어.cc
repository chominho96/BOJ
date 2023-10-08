#include <iostream>
#include <queue>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 21
#define MAX_SHARK_SIZE 401
#define MAX_COUNT 1001

using namespace std;

/*
 * [dir]
 * 1: 위
 * 2: 아래
 * 3: 왼쪽
 * 4: 오른쪽
 */

struct SHARK_INFO_ {
    int row;
    int col;
    int dir;
    int priority[5][4];     // [현재 방향][우선순위 4개]
};

struct CELL {
    priority_queue<int> shark;
    int smellNum = -1;
    int smellCnt = -1;
};

CELL MAP[MAX_SIZE][MAX_SIZE][MAX_COUNT];
SHARK_INFO_ SHARK_INFO[MAX_SHARK_SIZE];
int N, M, K;
int dx[]{0, -1, 1, 0, 0};
int dy[]{0, 0, 0, -1, 1};

bool isRoute(const int &row, const int &col) {
    return row >= 1 && row <= N && col >= 1 && col <= N;
}

bool isSuccess() {
    for (int i = 2; i <= M; i++) {
        if (!(SHARK_INFO[i].row == -1 && SHARK_INFO[i].col == -1)) return false;
    }
    return true;
}

void updateSmell(int cnt) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (MAP[i][j][cnt].smellNum != -1) continue;

            MAP[i][j][cnt].smellNum = MAP[i][j][cnt - 1].smellNum;
            MAP[i][j][cnt].smellCnt = MAP[i][j][cnt - 1].smellCnt;

            if (MAP[i][j][cnt].smellCnt > 0) {
                if (--MAP[i][j][cnt].smellCnt == 0) {
                    MAP[i][j][cnt].smellNum = -1;
                }
            }
        }
    }
}

void go(int num, int cnt) {
    int row = SHARK_INFO[num].row;
    int col = SHARK_INFO[num].col;
    int dir = SHARK_INFO[num].dir;

    if (row == -1 && col == -1) return;

    int next_row, next_col, next_dir;

    // 갈 방향 정하기
    bool isGoSuccess = false;
    for (int i = 0; i < 4; i++) {
        next_dir = SHARK_INFO[num].priority[dir][i];
        next_row = row + dx[next_dir];
        next_col = col + dy[next_dir];

        if (isRoute(next_row, next_col) && MAP[next_row][next_col][cnt].smellNum == -1) {
            isGoSuccess = true;
            break;
        }
    }

    if (!isGoSuccess) {
        for (int i = 0; i < 4; i++) {
            next_dir = SHARK_INFO[num].priority[dir][i];
            next_row = row + dx[next_dir];
            next_col = col + dy[next_dir];

            if (isRoute(next_row, next_col) && MAP[next_row][next_col][cnt].smellNum == num) {
                break;
            }
        }
    }

    // 정보 갱신
    MAP[next_row][next_col][cnt + 1].shark.push(num);
    SHARK_INFO[num].row = next_row;
    SHARK_INFO[num].col = next_col;
    SHARK_INFO[num].dir = next_dir;

    // 냄새 뿌리기
    MAP[next_row][next_col][cnt + 1].smellNum = num;
    MAP[next_row][next_col][cnt + 1].smellCnt = K;
}

void goOut(int cnt) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (MAP[i][j][cnt].shark.size() <= 1) continue;

            while (MAP[i][j][cnt].shark.size() > 1) {
                int current = MAP[i][j][cnt].shark.top();
                MAP[i][j][cnt].shark.pop();

                SHARK_INFO[current].row = -1;
                SHARK_INFO[current].col = -1;
            }

            // 냄새 갱신
            int winner = MAP[i][j][cnt].shark.top();
            MAP[i][j][cnt].smellNum = winner;
            MAP[i][j][cnt].smellCnt = K;
        }
    }
}

int main() {
    FASTIO;
    cin >> N >> M >> K;

    int input;
    for (int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> input;
            if (input != 0) {
                MAP[i][j][0].shark.push(input);
                SHARK_INFO[input].row = i;
                SHARK_INFO[input].col = j;
                MAP[i][j][0].smellNum = input;
                MAP[i][j][0].smellCnt = K;
            }
        }
    }

    for (int i = 1; i <= M; i++) {
        cin >> SHARK_INFO[i].dir;
    }

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> SHARK_INFO[i].priority[j][k];
            }
        }
    }

    int cnt = 1;
    while (true) {

        if (cnt > 1000) break;

        for (int i = 1; i <= M; i++) {
            go(i, cnt - 1);
        }
        goOut(cnt);
        updateSmell(cnt);

        if (isSuccess()) {
            cout << cnt << endl;
            return 0;
        }

        cnt++;
    }

    cout << -1 << endl;
}