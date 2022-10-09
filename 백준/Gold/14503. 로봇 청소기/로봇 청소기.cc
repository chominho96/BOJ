#include <iostream>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 51

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int N, M;
int r, c, d;
/*
*  d == 0 : 북쪽
*  d == 1 : 동쪽
*  d == 2 : 남쪽
*  d == 3 : 서쪽
*/

int dx[]{ -1, 0, 1, 0 };
int dy[]{ 0, 1, 0, -1 };

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= M;
}

int ans = 0;
void DFS(int row, int col, int dir) {

	if (!visited[row][col]) {
		visited[row][col] = true;
		ans++;
	}


	int next_dir = dir;
	bool success = false;
	for (int i = 0; i < 4; i++) {
		next_dir = (next_dir + 3) % 4;

		int next_row = row + dx[next_dir];
		int next_col = col + dy[next_dir];

		if (isRoute(next_row, next_col) && MAP[next_row][next_col] == 0 && !visited[next_row][next_col]) {
			success = true;

			DFS(next_row, next_col, next_dir);
		}
	}

	if (!success) {
		int next_dir2 = (dir + 2) % 4;
		int next_row = row + dx[next_dir2];
		int next_col = col + dy[next_dir2];
		if (!isRoute(next_row, next_col) || MAP[next_row][next_col] == 1) {
			cout << ans << '\n';
			exit(0);
		}
		else {
			DFS(next_row, next_col, dir);
		}
	}

}


int main() {
	FASTIO;
	cin >> N >> M >> r >> c >> d;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}

	DFS(r + 1, c + 1, d);

}