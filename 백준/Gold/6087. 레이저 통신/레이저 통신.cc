#include <iostream>
#include <queue>
#define MAX_SIZE 101
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int W, H;
int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][4];
int startRow = -1, startCol, endRow, endCol;

int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };
// 0 : col++
// 1 : col--
// 2 : row++
// 3 : row--

struct node {
	int row;
	int col;
	int dir;
	int len;
};

int ans = 987654321;

void BFS() {
	
	queue<node> que;
	que.push({ startRow, startCol, -1, 0 });
	
	for (int i = 0; i < 4; i++) {
		visited[startRow][startCol][i] = true;
	}

	while (!que.empty()) {
		node current = que.front();
		que.pop();

		if (current.row == endRow && current.col == endCol) {
			if (current.len < ans) {
				ans = current.len;
			}
			continue;
		}

		// left
		for (int i = current.col - 1; i > 0; i--) {
			if (MAP[current.row][i] == '*') {
				break;
			}
			node next;
			if (current.dir != -1 && current.dir != 1) {
				// 방향이 바뀐 케이스
				next = { current.row, i, 1, current.len + 1 };
			}
			else {
				next = { current.row, i, 1, current.len };
			}

			if (!visited[next.row][next.col][next.dir]) {
				visited[next.row][next.col][next.dir] = true;
				que.push(next);
			}
		}
		

		// right
		for (int i = current.col + 1; i <= W; i++) {
			if (MAP[current.row][i] == '*') {
				break;
			}
			node next;
			if (current.dir != -1 && current.dir != 0) {
				// 방향이 바뀐 케이스
				next = { current.row, i, 0, current.len + 1 };
			}
			else {
				next = { current.row, i, 0, current.len };
			}

			if (!visited[next.row][next.col][next.dir]) {
				visited[next.row][next.col][next.dir] = true;
				que.push(next);
			}
		}

		// up
		for (int i = current.row - 1; i > 0; i--) {
			if (MAP[i][current.col] == '*') {
				break;
			}
			node next;
			if (current.dir != -1 && current.dir != 3) {
				// 방향이 바뀐 케이스
				next = { i, current.col, 3, current.len + 1 };
			}
			else {
				next = { i, current.col, 3, current.len };
			}

			if (!visited[next.row][next.col][next.dir]) {
				visited[next.row][next.col][next.dir] = true;
				que.push(next);
			}
		}
		

		// down
		for (int i = current.row + 1; i <= H; i++) {
			if (MAP[i][current.col] == '*') {
				break;
			}
			node next;
			if (current.dir != -1 && current.dir != 2) {
				// 방향이 바뀐 케이스
				next = { i, current.col, 2, current.len + 1 };
			}
			else {
				next = { i, current.col, 2, current.len };
			}

			if (!visited[next.row][next.col][next.dir]) {
				visited[next.row][next.col][next.dir] = true;
				que.push(next);
			}
		}
	}
	
}

int main() {

	FASTIO;

	cin >> W >> H;

	// 1. input & make MAP
	string str;
	for (int i = 0; i < H; i++) {
		cin >> str;
		for (int j = 0; j < W; j++) {
			MAP[i + 1][j + 1] = str[j];
			if (str[j] == 'C') {
				if (startRow == -1) {
					startRow = i + 1;
					startCol = j + 1;
				}
				else {
					endRow = i + 1;
					endCol = j + 1;
				}
			}
		}
	}

	// 2. BFS
	BFS();

	cout << ans << '\n';


}