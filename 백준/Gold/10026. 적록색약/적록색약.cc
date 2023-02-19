#include <iostream>
#include <queue>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 101

using namespace std;

int n;
char MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

int blind_ans = 0; // 색맹
int non_blind_ans = 0; // 비색맹

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= n && col >= 1 && col <= n;
}

void BFS(int row, int col, bool blind) {
	blind ? blind_ans++ : non_blind_ans++;

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

			if (isRoute(next_row, next_col) && !visited[next_row][next_col]) {
				if (blind) {
					if ((MAP[row][col] == 'B' && MAP[next_row][next_col] == 'B') || (MAP[row][col] != 'B' && MAP[next_row][next_col] != 'B')) {
						visited[next_row][next_col] = true;
						que.push({ next_row, next_col });
					}
				}
				else if (MAP[row][col] == MAP[next_row][next_col]) {
					visited[next_row][next_col] = true;
					que.push({ next_row, next_col });
				}
			}
		}
	}
}

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			visited[i][j] = false;
		}
	}
}

int main() {
	FASTIO;
	cin >> n;

	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			MAP[i + 1][j + 1] = str[j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				BFS(i, j, true);
			}
		}
	}
	init();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				BFS(i, j, false);
			}
		}
	}

	cout << non_blind_ans << ' ' << blind_ans << endl;
}