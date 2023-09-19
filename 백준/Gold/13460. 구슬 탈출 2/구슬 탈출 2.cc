#include <iostream>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 11

using namespace std;

int N, M;
char MAP[MAX_SIZE][MAX_SIZE];
int ans = -1;
pair<int, int> BLUE, RED, HOLE;
int dx[]{ 0, 1, 0, -1 };
int dy[]{ 1, 0, -1, 0 };

/*
* <dir>
* 0: 오른쪽
* 1: 아래쪽
* 2: 왼쪽
* 3: 위쪽
*/

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= M;
}

// 1은 red만 들어간 경우
// 0은 아무것도 들어가지 않은 경우
// -1은 blue만 들어가거나 둘다 들어간 경우
int moveBall(pair<int, int>& blue, pair<int, int>& red, int dir) {
    
	bool isRedGoIn = false;
	
	while (true) {
		bool isBlueMove = false;
		bool isRedMove = false;

		// blue 움직이기
		int next_row = blue.first + dx[dir];
		int next_col = blue.second + dy[dir];

		if (isRoute(next_row, next_col)) {
			if (MAP[next_row][next_col] == 'O') return -1;
			else if (MAP[next_row][next_col] == '.' && !(next_row == red.first && next_col == red.second)) {
				isBlueMove = true;
				blue = { next_row, next_col };
			}
		}

		// red 움직이기
		if (!isRedGoIn) {
			next_row = red.first + dx[dir];
			next_col = red.second + dy[dir];

			if (isRoute(next_row, next_col)) {
				if (MAP[next_row][next_col] == 'O') {
					isRedMove = true;
					isRedGoIn = true;
					red = { next_row, next_col };
				}
				else if (MAP[next_row][next_col] == '.' && !(next_row == blue.first && next_col == blue.second)) {
					isRedMove = true;
					red = { next_row, next_col };
				}
			}
		}

		if (!isBlueMove && !isRedMove) break;
	}

	if (isRedGoIn) return 1;
	return 0;
}

void calc(pair<int, int> blue, pair<int, int> red, int dir, int cnt) {
	
	// end condition
	if (cnt > 10) return;
	if (ans != -1 && cnt >= ans) return;

	// move & go next
	int current = moveBall(blue, red, dir);
	if (current == -1) return;
	else if (current == 1) {
		ans = cnt;
		return;
	}

	switch (dir)
	{
	case 0:		// 오른쪽
		calc(blue, red, 1, cnt + 1);
		calc(blue, red, 3, cnt + 1);
		break;
	case 1:		// 아래쪽
		calc(blue, red, 0, cnt + 1);
		calc(blue, red, 2, cnt + 1);
		break;
	case 2:		// 왼쪽
		calc(blue, red, 1, cnt + 1);
		calc(blue, red, 3, cnt + 1);
		break;
	default:	// 위쪽
		calc(blue, red, 0, cnt + 1);
		calc(blue, red, 2, cnt + 1);
		break;
	}
}

int main() {
	FASTIO;
	cin >> N >> M;
	string input;
	for (int i = 1; i <= N; i++) {
		cin >> input;

		for (int j = 1; j <= M; j++) {
			MAP[i][j] = input[j - 1];

			if (input[j - 1] == 'B') {
				BLUE = { i, j };
				MAP[i][j] = '.';
			}
			else if (input[j - 1] == 'R') {
				RED = { i, j };
				MAP[i][j] = '.';
			}
			else if (input[j - 1] == 'O') HOLE = { i, j };
		}
	}

	for (int i = 0; i < 4; i++) {
		calc(BLUE, RED, i, 1);
	}

	cout << ans << endl;
}