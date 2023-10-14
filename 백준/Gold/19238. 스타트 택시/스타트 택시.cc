#include <iostream>
#include <utility>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 21
#define MAX_PERSON_SIZE 402

using namespace std;

struct node {
	int value;			// 0은 빈칸, 1은 벽
	int start = -1;		// 누가 이 node를 출발지로 하는지
};

struct bfsNode {
	int row;
	int col;
	int value;
};

struct compareNode {
	int row;
	int col;
};

struct compare {
	bool operator()(const compareNode& n1, const compareNode& n2) {
		if (n1.row == n2.row) return n1.col > n2.col;
		return n1.row > n2.row;
	}
};

node MAP[MAX_SIZE][MAX_SIZE];
int N, M, ENERGY;
pair<int, int> DRIVER;
pair<int, int> DEST[MAX_PERSON_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[]{ -1, 0, 0, 1 };
int dy[]{ 0, -1, 1, 0 };
int CURRENT_GUEST = -1;

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

// 어떤 승객을 태울지 찾는 BFS
// CURRENT_GUEST를 설정하고, 거리를 return
int findGuestBfs() {

	if (MAP[DRIVER.first][DRIVER.second].start != -1) {
		CURRENT_GUEST = MAP[DRIVER.first][DRIVER.second].start;
		MAP[DRIVER.first][DRIVER.second].start = -1;
		return 0;
	}

	init();
	queue<bfsNode> que;
	que.push({ DRIVER.first, DRIVER.second, 0 });
	visited[DRIVER.first][DRIVER.second] = true;
	priority_queue<compareNode, vector<compareNode>, compare> pq;
	int current_max_value = 0;

	while (!que.empty()) {
		int current_row = que.front().row;
		int current_col = que.front().col;
		int current_value = que.front().value;

		que.pop();

		if (current_value > current_max_value) {
			if (!pq.empty()) {
				CURRENT_GUEST = MAP[pq.top().row][pq.top().col].start;
				DRIVER = { pq.top().row, pq.top().col };
				MAP[pq.top().row][pq.top().col].start = -1;
				return current_value;
			}

			current_max_value = current_value;
		}

		for (int i = 0; i < 4; i++) {
			int next_row = current_row + dx[i];
			int next_col = current_col + dy[i];

			if (isRoute(next_row, next_col) && !visited[next_row][next_col] && MAP[next_row][next_col].value == 0) {
				if (MAP[next_row][next_col].start != -1) {
					pq.push({ next_row, next_col });
				}
				
				visited[next_row][next_col] = true;
				que.push({ next_row, next_col, current_value + 1 });
			}
		}
	}

	return -1;
}

// 승객을 목적지로 데려가는 BFS
// 걸린 거리를 return
int bfs(int end_row, int end_col) {

	if (DRIVER.first == end_row && DRIVER.second == end_col) {
		DRIVER = { end_row, end_col };
		return 0;
	}

	init();
	queue<bfsNode> que;
	que.push({ DRIVER.first, DRIVER.second, 0 });
	visited[DRIVER.first][DRIVER.second] = true;

	while (!que.empty()) {
		int current_row = que.front().row;
		int current_col = que.front().col;
		int current_value = que.front().value;

		que.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = current_row + dx[i];
			int next_col = current_col + dy[i];

			if (isRoute(next_row, next_col) && !visited[next_row][next_col] && MAP[next_row][next_col].value == 0) {
				if (next_row == end_row && next_col == end_col) {
					DRIVER = { end_row, end_col };
					return current_value + 1;
				}

				visited[next_row][next_col] = true;
				que.push({ next_row, next_col, current_value + 1 });
			}
		}
	}

	return -1;
}

int main() {
	FASTIO;
	cin >> N >> M >> ENERGY;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j].value;
		}
	}
	cin >> DRIVER.first >> DRIVER.second;

	int start_row, start_col, end_row, end_col;
	for (int i = 1; i <= M; i++) {
		cin >> start_row >> start_col >> DEST[i].first >> DEST[i].second;
		MAP[start_row][start_col].start = i;
	}

	for (int i = 1; i <= M; i++) {
		int energy = findGuestBfs();
		if (energy == -1 || energy > ENERGY) {
			cout << -1 << endl;
			return 0;
		}
		ENERGY -= energy;

		energy = bfs(DEST[CURRENT_GUEST].first, DEST[CURRENT_GUEST].second);
		if (energy == -1 || energy > ENERGY) {
			cout << -1 << endl;
			return 0;
		}
		ENERGY += energy;
	}

	cout << ENERGY << endl;
}