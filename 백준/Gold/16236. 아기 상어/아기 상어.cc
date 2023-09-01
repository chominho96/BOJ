#include <iostream>
#include <utility>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 21

using namespace std;

struct node {
	int row;
	int col;
	int dist;
};

int N;
int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
pair<int, int> baby;
int dx[]{ -1, 0, 1, 0 };
int dy[]{ 0, -1, 0, 1 };
int babySize = 2;
int eat = 0;

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			visited[i][j] = false;
		}
	}
}

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= N;
}

int bfs() {
	init();
	visited[baby.first][baby.second] = true;
	queue<node> que;
	que.push({ baby.first, baby.second, 0 });

	int ansDist = -1;		// 먹을 수 있는 물고기를 찾았는지 여부
	int ansRow = -1;
	int ansCol = -1;
	
	while (!que.empty()) {
		node current = que.front();
		que.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = current.row + dx[i];
			int next_col = current.col + dy[i];

			if (current.dist == ansDist) {	// end condition
				
				if (++eat == babySize) {
					eat = 0;
					babySize++;
				}

				MAP[ansRow][ansCol] = 0;
				baby = { ansRow, ansCol };
				return ansDist;
			}

			if (isRoute(next_row, next_col) && !visited[next_row][next_col] && MAP[next_row][next_col] <= babySize) {

				if (MAP[next_row][next_col] != 0 && MAP[next_row][next_col] < babySize) {

					if (ansDist == -1) {
						ansDist = current.dist + 1;
						ansRow = next_row;
						ansCol = next_col;
					}
					else if (ansRow > next_row || (ansRow == next_row && ansCol > next_col)) {
						ansRow = next_row;
						ansCol = next_col;
					}
				}

				visited[next_row][next_col] = true;
				que.push({ next_row, next_col, current.dist + 1 });
			}
		}
	}
	return -1;
}

int main() {
	FASTIO;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 9) {
				MAP[i][j] = 0;
				baby = { i , j };
			}
		}
	}

	int ans = 0;
	
	while (true) {
		int current = bfs();
		if (current == -1) break;
		ans += current;
	}

	cout << ans << endl;
}