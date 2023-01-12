#include <iostream>
#include <vector>
#define MAX_SIZE 21
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define enld '\n'

using namespace std;

int R, C;
char MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
bool alpha_visited[26];
int ans = -1;
int dx[]{ 1, -1, 0, 0 };
int dy[]{ 0, 0, 1, -1 };

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= R && col >= 1 && col <= C;
}

void DFS(int row, int col, int current) {
	if (current > ans) ans = current;
	
	for (int i = 0; i < 4; i++) {
		int next_row = row + dx[i];
		int next_col = col + dy[i];

		if (isRoute(next_row, next_col) && !visited[next_row][next_col] && !alpha_visited[MAP[next_row][next_col] - 'A']) {
			visited[next_row][next_col] = true;
			alpha_visited[MAP[next_row][next_col] - 'A'] = true;
			DFS(next_row, next_col, current + 1);
			visited[next_row][next_col] = false;
			alpha_visited[MAP[next_row][next_col] - 'A'] = false;
		}
	}
}

int main() {
	FASTIO;
	cin >> R >> C;
	string str;
	for (int i = 1; i <= R; i++) {
		cin >> str;
		for (int j = 1; j <= C; j++) {
			MAP[i][j] = str[j - 1];
		}
	}
	
	visited[1][1] = true;
	alpha_visited[MAP[1][1] - 'A'] = true;
	DFS(1, 1, 1);
	cout << ans << endl;
}