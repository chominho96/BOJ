#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 1001

using namespace std;

char MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };
char dir[]{ 'L', 'R', 'U', 'D' };

int N, M;
int ans = 0;

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= M;
}

void DFS(int row, int col, bool first, bool opposite) {
	if (!isRoute(row, col) || visited[row][col]) return;
	visited[row][col] = true;
	if (first) ans++;

	if (opposite) {
		for (int i = 0; i < 4; i++) {
			int next_row = row + dx[i];
			int next_col = col + dy[i];
			char next_dir = dir[i];
			if (isRoute(next_row, next_col) && MAP[next_row][next_col] == next_dir) {
				DFS(next_row, next_col, false, true);
			}
		}
	}
	else {
		switch (MAP[row][col])
		{
		case 'U':
			DFS(row - 1, col, false, false);
			break;
		case 'D':
			DFS(row + 1, col, false, false);
			break;
		case 'L':
			DFS(row, col - 1, false, false);
			break;
		case 'R':
			DFS(row, col + 1, false, false);
			break;
		default:
			break;
		}

		for (int i = 0; i < 4; i++) {
			int next_row = row + dx[i];
			int next_col = col + dy[i];
			char next_dir = dir[i];

			if (isRoute(next_row, next_col) && MAP[next_row][next_col] == next_dir) {
				DFS(next_row, next_col, false, true);
			}
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> M;

	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) {
			MAP[i][j] = str[j - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			DFS(i, j, true, false);
		}
	}
	cout << ans << endl;
}