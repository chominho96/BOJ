#include <iostream>
#include <cmath>
#include <queue>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 65
#define MAX_COUNT 1001

using namespace std;

struct ICE {
	int value;
	bool decrease = false;
};

ICE MAP[MAX_SIZE][MAX_SIZE][MAX_COUNT];
bool visited[MAX_SIZE][MAX_SIZE];
int N, Q, L;
int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= N;
}

int bfs(int row, int col) {
	int ans = 1;
	queue<pair<int, int>> que;
	que.push({ row, col });
	visited[row][col] = true;
	
	while (!que.empty()) {
		int current_row = que.front().first;
		int current_col = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = current_row + dx[i];
			int next_col = current_col + dy[i];

			if (isRoute(next_row, next_col) && !visited[next_row][next_col] && MAP[next_row][next_col][Q].value > 0) {
				ans++;
				visited[next_row][next_col] = true;
				que.push({ next_row, next_col });
			}
		}
	}
	return ans;
}

int calcMaxIce() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j] && MAP[i][j][Q].value > 0) {
				ans = max(ans, bfs(i, j));
			}
		}
	}
	return ans;
}

int calcSumIce() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j][Q].decrease) MAP[i][j][Q].value--;
			ans += MAP[i][j][Q].value;
		}
	}
	return ans;
}

void roll(int l, int cnt) {
	// 얼음 이동
	int unit = pow(2, l);
	for (int i = 1; i <= N; i += unit) {
		for (int j = 1; j <= N; j += unit) {

			// i, j가 왼쪽 위 시작점
			int target_row = i;
			int target_col = j + unit - 1;
			for (int n = i; n < i + unit; n++) {
				for (int m = j; m < j + unit; m++) {

					if (MAP[n][m][cnt].decrease) MAP[n][m][cnt].value--;
					MAP[target_row][target_col][cnt + 1].value = MAP[n][m][cnt].value;
					target_row++;
				}
				target_row = i;
				target_col--;
			}
		}
	}

	// 얼음 양 줄이기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j][cnt + 1].value == 0) continue;

			int current = 0;
			for (int k = 0; k < 4; k++) {
				int next_row = i + dx[k];
				int next_col = j + dy[k];

				if (isRoute(next_row, next_col) && MAP[next_row][next_col][cnt + 1].value > 0) {
					current++;
				}
			}
			if (current < 3) MAP[i][j][cnt + 1].decrease = true;
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> Q;
	N = pow(2, N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j][0].value;
		}
	}

	for (int i = 0; i < Q; i++) {
		cin >> L;
		roll(L, i);
	}
	int sum = calcSumIce();
	int max = calcMaxIce();

	cout << sum << endl << max << endl;
}