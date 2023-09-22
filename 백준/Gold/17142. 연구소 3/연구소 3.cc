#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 51

using namespace std;

struct node {
	int row;
	int col;
	int time;
};

int N, M;
int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
vector<pair<int, int>> VIRUS;
vector<pair<int, int>> ACTIVE_VIRUS;
int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };
int targetNumber;
int ans = -1;

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= N;
}

void init() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visited[i][j] = false;
		}
	}
}

void spread() {
	init();
	int current = VIRUS.size();
	int current_ans = 0;
	queue<node> que;
	for (int i = 0; i < ACTIVE_VIRUS.size(); i++) {
		que.push({ ACTIVE_VIRUS[i].first, ACTIVE_VIRUS[i].second, 0 });
		visited[ACTIVE_VIRUS[i].first][ACTIVE_VIRUS[i].second] = true;
	}

	while (!que.empty()) {
		int current_row = que.front().row;
		int current_col = que.front().col;
		int current_time = que.front().time;
		que.pop();

		current_ans = current_time;

		for (int i = 0; i < 4; i++) {
			int next_row = current_row + dx[i];
			int next_col = current_col + dy[i];
			if (isRoute(next_row, next_col) && MAP[next_row][next_col] != 1 && !visited[next_row][next_col]) {
				visited[next_row][next_col] = true;
				que.push({ next_row, next_col, current_time + 1 });

				if (MAP[next_row][next_col] != 2) {
					if (++current == targetNumber) {
						if (ans == -1) ans = current_time + 1;
						else ans = min(ans, current_time + 1);

						return;
					}
				}
			}
		}
	}
}

void calc(int idx, int cnt) {

	ACTIVE_VIRUS.push_back(VIRUS[idx]);

	if (cnt == M) {
		spread();
		ACTIVE_VIRUS.pop_back();
		return;
	}

	// go next
	for (int i = idx + 1; i < VIRUS.size(); i++) {
		calc(i, cnt + 1);
	}

	ACTIVE_VIRUS.pop_back();
}

int main() {
	FASTIO;
	cin >> N >> M;
	targetNumber = N * N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 2) VIRUS.push_back({ i, j });
			else if (MAP[i][j] == 1) targetNumber--;
		}
	}

	// edge case: 모든 칸에 바이러스가 있는 경우
	if (targetNumber == VIRUS.size()) {
		cout << 0 << endl;
		return 0;
	}

	for (int i = 0; i < VIRUS.size(); i++) {
		calc(i, 1);
	}

	cout << ans << endl;
}