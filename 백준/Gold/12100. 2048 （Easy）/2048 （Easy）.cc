#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 21

using namespace std;

int N;
vector<vector<int>> MAP;
int ans = 0;

/*
* [dir]
* 0: 오른쪽
* 1: 아래쪽
* 2: 왼쪽
* 3: 위쪽
*/

int getMax(vector<vector<int>>& map) {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans = max(ans, map[i][j]);
		}
	}

	return ans;
}


void calc(vector<vector<int>> map, int dir, int cnt) {

	// 방향으로 이동
	int next_row, next_col;
	int finish_row, finish_col;

	switch (dir) {
	case 0:		// 오른쪽
		
		for (int i = 1; i <= N; i++) {

			finish_col = N + 1;

			for (int j = N - 1; j >= 1; j--) {

				if (map[i][j] == 0) continue;

				next_col = j;

				for (int k = j + 1; k <= N; k++) {
					if (map[i][k] == 0) next_col = k;
					else if (map[i][k] == map[i][j] && k < finish_col) {
						next_col = k;
						break;
					}
					else break;
				}

				if (next_col != j && map[i][next_col] == map[i][j]) {
					map[i][next_col] *= 2;
					map[i][j] = 0;
					finish_col = next_col;
				}
				else if (next_col != j) {
					map[i][next_col] = map[i][j];
					map[i][j] = 0;
				}
			}
		}
		break;
	case 1:		// 아래쪽
		
		for (int j = 1; j <= N; j++) {
			finish_row = N + 1;

			for (int i = N - 1; i >= 1; i--) {

				if (map[i][j] == 0) continue;
				
				next_row = i;
				
				for (int k = i + 1; k <= N; k++) {
					if (map[k][j] == 0) next_row = k;
					else if (map[k][j] == map[i][j] && k < finish_row) {
						next_row = k;
						break;
					}
					else break;
				}

				if (next_row != i && map[next_row][j] == map[i][j]) {
					map[next_row][j] *= 2;
					map[i][j] = 0;
					finish_row = next_row;
				}
				else if (next_row != i) {
					map[next_row][j] = map[i][j];
					map[i][j] = 0;
				}
			}
		}
		break;
	case 2:		// 왼쪽
		
		for (int i = 1; i <= N; i++) {
			finish_col = 0;
			for (int j = 2; j <= N; j++) {
				
				if (map[i][j] == 0) continue;

				next_col = j;

				for (int k = j - 1; k >= 1; k--) {
					if (map[i][k] == 0) next_col = k;
					else if (map[i][k] == map[i][j] && k > finish_col) {
						next_col = k;
						break;
					}
					else break;
				}

				if (next_col != j && map[i][next_col] == map[i][j]) {
					map[i][next_col] *= 2;
					map[i][j] = 0;
					finish_col = next_col;
				}
				else if (next_col != j) {
					map[i][next_col] = map[i][j];
					map[i][j] = 0;
				}
			}
		}
		break;
	default:	// 위쪽
		
		for (int j = 1; j <= N; j++) {
			finish_row = 0;
			for (int i = 2; i <= N; i++) {

				if (map[i][j] == 0) continue;

				next_row = i;

				for (int k = i - 1; k >= 1; k--) {
					if (map[k][j] == 0) next_row = k;
					else if (map[k][j] == map[i][j] && k > finish_row) {
						next_row = k;
						break;
					}
					else break;
				}

				if (next_row != i && map[next_row][j] == map[i][j]) {
					map[next_row][j] *= 2;
					map[i][j] = 0;
					finish_row = next_row;
				}
				else if (next_row != i) {
					map[next_row][j] = map[i][j];
					map[i][j] = 0;
				}
			}
		}
		break;
	}
	// 5번 다 돈 경우 최대값 체크
	if (cnt == 5) {
		ans = max(getMax(map), ans);
		return;
	}

	// 다음으로
	for (int i = 0; i < 4; i++) {
		calc(map, i, cnt + 1);
	}
}

int main() {
	FASTIO;
	cin >> N;
	MAP.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		MAP[i].resize(N + 1);
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		calc(MAP, i, 1);
	}

	cout << ans << endl;
}