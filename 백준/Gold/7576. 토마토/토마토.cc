#include <iostream>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 1001

using namespace std;

struct tomato {
	int row;
	int col;
	int value;
};

int M, N;
int MAP[MAX_SIZE][MAX_SIZE];
int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= M;
}

void BFS() {
	int ans = 0;
	queue<tomato> que;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 1) {
				que.push({ i, j, 0 });
			}
		}
	}

	while (!que.empty()) {
		tomato current = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int next_row = current.row + dx[i];
			int next_col = current.col + dy[i];

			if (isRoute(next_row, next_col) && MAP[next_row][next_col] == 0) {
				que.push({ next_row, next_col, current.value + 1 });
				MAP[next_row][next_col] = 1;
				if (current.value + 1 > ans) {
					ans = current.value + 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 0) {
				cout << -1 << endl;
				return;
			}
		}
	}

	cout << ans << endl;
}

int main() {
	FASTIO;
	cin >> M >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}

	BFS();
}