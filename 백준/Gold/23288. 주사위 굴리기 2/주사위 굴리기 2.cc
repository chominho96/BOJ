#include <iostream>
#include <queue>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 21

using namespace std;

struct dice {
	int up;
	int down;
	int north;
	int south;
	int west;
	int east;
};

int N, M, K;
int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[]{ 0, 1, 0, -1 };
int dy[]{ 1, 0, -1, 0 };

int ans = 0;
dice DICE = { 1, 6, 2, 5, 4, 3 };
int row = 1;
int col = 1;
int dir = 0;

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			visited[i][j] = false;
		}
	}
}

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= M;
}

int bfs(int row, int col) {

	int ans = 1;
	
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
			
			if (isRoute(next_row, next_col) && !visited[next_row][next_col] && MAP[next_row][next_col] == MAP[row][col]) {
				ans++;
				visited[next_row][next_col] = true;
				que.push({ next_row, next_col });
			}
		}
	}

	return ans;
}

void roll() {
	switch (dir)
	{
	case 0:		// 오른쪽
		DICE = { DICE.west, DICE.east, DICE.north, DICE.south, DICE.down, DICE.up };
		break;
	case 1:		// 아래쪽
		DICE = { DICE.north, DICE.south, DICE.down, DICE.up, DICE.west, DICE.east };
		break;
	case 2:		// 왼쪽
		DICE = { DICE.east, DICE.west, DICE.north, DICE.south, DICE.up, DICE.down };
		break;
	default:	// 위쪽
		DICE = { DICE.south, DICE.north, DICE.up, DICE.down, DICE.west, DICE.east };
		break;
	}
}

void calc() {
	// 1. 한 칸 구르기
	int next_row = row + dx[dir];
	int next_col = col + dy[dir];

	if (!isRoute(next_row, next_col)) {
		dir = (dir + 2) % 4;
		next_row = row + dx[dir];
		next_col = col + dy[dir];
	}

	roll();
	row = next_row;
	col = next_col;

	// 2. 점수 획득
	ans += bfs(row, col) * MAP[row][col];

	// 3. dir 갱신
	if (DICE.down > MAP[row][col]) dir = (dir + 1) % 4;
	else if (DICE.down < MAP[row][col]) dir = (dir + 3) % 4;
}

int main() {
	FASTIO;
	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}
	
	while (K--) {
		calc();
	}

	cout << ans << endl;
}
