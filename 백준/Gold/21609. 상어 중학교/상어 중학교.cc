#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 21
#define MAX_COUNT 1001

using namespace std;

struct node {
	int rainbow;
	int row;
	int col;
	int size;
};

int MAP[MAX_SIZE][MAX_SIZE][MAX_COUNT];
int COUNT = 1;
bool visited[MAX_SIZE][MAX_SIZE];
int N, M;
int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };
int ans = 0;

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			visited[i][j] = false;
		}
	}
}

void rainbowInit() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (MAP[i][j][COUNT] == 0) visited[i][j] = false;
		}
	}
}

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= N;
}

node bfs(int row, int col) {
	rainbowInit();
	queue<pair<int, int>> que;
	que.push({ row, col });
	visited[row][col] = true;
	int ans = 1;
	int rainbow = 0;

	while (!que.empty()) {
		int current_row = que.front().first;
		int current_col = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = current_row + dx[i];
			int next_col = current_col + dy[i];

			if (isRoute(next_row, next_col) && !visited[next_row][next_col] && (MAP[row][col][COUNT] == MAP[next_row][next_col][COUNT] || MAP[next_row][next_col][COUNT] == 0)) {

				if (MAP[next_row][next_col][COUNT] == 0) rainbow++;
				ans++;
				visited[next_row][next_col] = true;
				que.push({ next_row, next_col });
			}
		}
	}

	return { rainbow, row, col, ans };
}

void blankBfs(int row, int col) {
	init();

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

			if (isRoute(next_row, next_col) && !visited[next_row][next_col] && (MAP[row][col][COUNT] == MAP[next_row][next_col][COUNT] || MAP[next_row][next_col][COUNT] == 0)) {
				visited[next_row][next_col] = true;
				MAP[next_row][next_col][COUNT] = -2;
				que.push({ next_row, next_col });
			}
		}
	}

	MAP[row][col][COUNT] = -2;
}

void gravity() {
	for (int j = 1; j <= N; j++) {
		for (int i = N; i >= 1; i--) {
			if (MAP[i][j][COUNT] == -1 || MAP[i][j][COUNT] == -2) continue;
			
			int next_row = i;

			for (int k = i + 1; k <= N; k++) {
				if (MAP[k][j][COUNT] == -2) next_row = k;
				else break;
			}

			if (next_row != i) {
				MAP[next_row][j][COUNT] = MAP[i][j][COUNT];
				MAP[i][j][COUNT] = -2;
			}
		}
	}
}

void roll() {
	int row = N;
	int col = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[row][col][COUNT + 1] = MAP[i][j][COUNT];
			row--;
		}
		row = N;
		col++;
	}

	COUNT++;
}


int main() {
	FASTIO;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j][COUNT];
		}
	}

	while (true) {

		init();

		node maxNode{ 0, 0, 0, -1 };

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visited[i][j] && MAP[i][j][COUNT] != -2 && MAP[i][j][COUNT] != -1 && MAP[i][j][COUNT] != 0) {
					node current = bfs(i, j);
					if (current.size > maxNode.size) {
						maxNode = current;
					}
					else if (current.size == maxNode.size) {
						if (current.rainbow > maxNode.rainbow) {
							maxNode = current;
						}
						else if (current.rainbow == maxNode.rainbow) {
							if (current.row > maxNode.row) {
								maxNode = current;
							}
							else if (current.col > maxNode.col) {
								maxNode = current;
							}
						}
					}
				}
			}
		}

		if (maxNode.size == -1 || maxNode.size == 1) {
			break;
        }

		ans += pow(maxNode.size, 2);
		blankBfs(maxNode.row, maxNode.col);

		gravity();

		roll();

		gravity();
	}
	
	cout << ans << endl;
	
}