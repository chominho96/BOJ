#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 51

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
int SPREAD[MAX_SIZE][MAX_SIZE];
int TEMP[MAX_SIZE][MAX_SIZE];

int R, C, T;
int cleanerRow = -1;
int cleanerCol = -1;
int dx[]{ 1, -1, 0, 0 };
int dy[]{ 0, 0, 1, -1 };

int upCleanCnt = 0;
int downCleanCnt = 0;

// 공통적으로 두 공기청정기는 모두 오른쪽/왼쪽으로는 C - 1만큼 이동
// 위 공기청정기는 cleanerRow - 1만큼 이동
// 아래 공기청정기는 R - cleanerRow - 1만큼 이동


bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= R && col >= 1 && col <= C && !(row == cleanerRow && col == cleanerCol) && !(row == cleanerRow + 1 && col == cleanerCol);
}

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			SPREAD[i][j] = 0;
		}
	}
}

void spread() {
	// 퍼질 양 계산
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {

			if (MAP[i][j] > 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int next_row = i + dx[k];
					int next_col = j + dy[k];

					if (isRoute(next_row, next_col)) {
						SPREAD[next_row][next_col] += MAP[i][j] / 5;
						cnt++;
					}
				}
				SPREAD[i][j] -= (int)(MAP[i][j] / 5) * cnt;
			}
		}
	}

	// 반영
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!(j == cleanerCol && (i == cleanerRow || i == cleanerRow + 1))) {	// 공기청정기로 들어가는 경우가 아니라면
				MAP[i][j] += SPREAD[i][j];
			}
		}
	}

	// 초기화
	init();
}

void clean(int dir) {

	// [dir]
	// [위 공기청정기] 0: 오른쪽, 1: 위쪽, 2: 왼쪽, 3: 아래쪽
	// [아래 공기청정기] 0: 오른쪽, 2: 아래쪽, 3: 왼쪽, 4: 위쪽
	
	switch (dir)
	{
	case 0:		
		for (int i = C - 1; i >= 2; i--) {	// 오른쪽
			MAP[cleanerRow][i + 1] = MAP[cleanerRow][i];
		}
		MAP[cleanerRow][2] = 0;

		for (int i = C - 1; i >= 2; i--) {	// 오른쪽
			MAP[cleanerRow + 1][i + 1] = MAP[cleanerRow + 1][i];
		}
		MAP[cleanerRow + 1][2] = 0;
		break;
	case 1:		
		for (int i = 2; i <= cleanerRow; i++) {	// 위쪽
			MAP[i - 1][C] = MAP[i][C];
		}
		MAP[cleanerRow - 1][C] = TEMP[cleanerRow][C];

		for (int i = R - 1; i >= cleanerRow + 1; i--) {	// 아래쪽
			MAP[i + 1][C] = MAP[i][C];
		}
		MAP[cleanerRow + 2][C] = TEMP[cleanerRow + 1][C];
		break;
	case 2:		
		for (int i = 2; i <= C; i++) {	// 왼쪽
			if (MAP[1][i - 1] == -1) {
				continue;
			}
			MAP[1][i - 1] = MAP[1][i];
		}
		MAP[1][C - 1] = TEMP[1][C];

		for (int i = 2; i <= C; i++) {	// 왼쪽
			if (MAP[R][i - 1] == -1) {
				continue;
			}
			MAP[R][i - 1] = MAP[R][i];
		}
		MAP[R][C - 1] = TEMP[R][C];
		break;
	default:	
		for (int i = cleanerRow - 2; i >= 1; i--) {	// 아래쪽
			MAP[i + 1][1] = MAP[i][1];
		}
		if (MAP[2][1] != -1) {
			MAP[2][1] = TEMP[1][1];
		}

		for (int i = cleanerRow + 3; i <= R; i++) {	// 위쪽
			MAP[i - 1][1] = MAP[i][1];
		}
		if (MAP[R - 1][1] != -1) {
			MAP[R - 1][1] = TEMP[R][1];
		}
		break;
	}
}

int calc() {
	int ans = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (MAP[i][j] != -1) ans += MAP[i][j];
		}
	}
	return ans;
}

int main() {
	FASTIO;
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == -1 && cleanerRow == -1) {
				cleanerRow = i;
				cleanerCol = j;
			}
		}
	}

	while (T--) {
		spread();

		TEMP[cleanerRow][C] = MAP[cleanerRow][C];
		TEMP[1][C] = MAP[1][C];
		TEMP[1][1] = MAP[1][1];
		
		TEMP[cleanerRow + 1][C] = MAP[cleanerRow + 1][C];
		TEMP[R][C] = MAP[R][C];
		TEMP[R][1] = MAP[R][1];

		for (int i = 0; i < 4; i++) {
			clean(i);
		}	
	}



	cout << calc() << endl;
}