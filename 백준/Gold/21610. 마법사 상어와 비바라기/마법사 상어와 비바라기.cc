#include <iostream>
#include <vector>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 51

using namespace std;

struct cloud {
	int row;
	int col;
	int value = 0;
};

int N, M;
int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
int dx[]{ 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[]{ 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int ddx[]{ 1, 1, -1, -1 };
int ddy[]{ 1, -1, 1, -1 };
vector<cloud> CLOUD;

void init() {
	CLOUD.push_back({ N, 1, 0 });
	CLOUD.push_back({ N, 2, 0 });
	CLOUD.push_back({ N - 1, 1, 0 });
	CLOUD.push_back({ N - 1, 2, 0 });
}

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= N;
}

cloud _move(int row, int col, const int& d, int s) {

	while (s--) {
		row += dx[d];
		col += dy[d];

		if (row == 0) {
			row = N;
		}
		else if (row == N + 1) {
			row = 1;
		}
		if (col == 0) {
			col = N;
		}
		else if (col == N + 1) {
			col = 1;
		}
	}

	return { row, col, 0 };
}

void moveWater(const int& d, const int& s) {

	for (int i = 0; i < CLOUD.size(); i++) {
		CLOUD[i] = _move(CLOUD[i].row, CLOUD[i].col, d, s);
		MAP[CLOUD[i].row][CLOUD[i].col]++;
		visited[CLOUD[i].row][CLOUD[i].col] = true;
	}

	for (int i = 0; i < CLOUD.size(); i++) {
		for (int j = 0; j < 4; j++) {
			int next_row = CLOUD[i].row + ddx[j];
			int next_col = CLOUD[i].col + ddy[j];

			if (isRoute(next_row, next_col) && MAP[next_row][next_col] > 0) {
				CLOUD[i].value++;
			}
		}
	}

	for (int i = 0; i < CLOUD.size(); i++) {
		MAP[CLOUD[i].row][CLOUD[i].col] += CLOUD[i].value;
	}

	CLOUD.clear();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j]) visited[i][j] = false;
			else if (MAP[i][j] >= 2) {
				CLOUD.push_back({ i, j, 0 });
				MAP[i][j] -= 2;
			}
		}
	}

}

int calc() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += MAP[i][j];
		}
	}
	return ans;
}

int main() {
	FASTIO;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}

	init();

	int d, s;
	while (M--) {
		cin >> d >> s;
		moveWater(d, s);
	}

	cout << calc() << endl;
}
