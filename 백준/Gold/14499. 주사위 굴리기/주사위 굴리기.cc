#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 21

using namespace std;

struct dice {
	int up;
	int down;
	int north;
	int south;
	int east;
	int west;
};

int MAP[MAX_SIZE][MAX_SIZE];
int N, M, x, y, K;
int dx[]{ 0, 0, 0, -1, 1 };
int dy[]{ 0, 1, -1, 0, 0 };
vector<int> ans;
dice DICE{ 0, 0, 0, 0, 0, 0 };

bool isRoute(const int& row, const int& col) {
	return row >= 0 && row < N && col >= 0 && col < M;
}

void roll(const int& dir) {
	switch (dir)
	{
	case 1:			// 오른쪽
		DICE = { DICE.west, DICE.east, DICE.north, DICE.south, DICE.up, DICE.down };
		break;
	case 2:			// 왼쪽
		DICE = { DICE.east, DICE.west, DICE.north, DICE.south, DICE.down, DICE.up };
		break;
	case 3:			// 위쪽
		DICE = { DICE.south, DICE.north, DICE.up, DICE.down, DICE.east, DICE.west };
		break;
	default:		// 아래쪽
		DICE = { DICE.north, DICE.south, DICE.down, DICE.up, DICE.east, DICE.west };
		break;
	}
}

int calc(const int& dir) {
	int next_row = x + dx[dir];
	int next_col = y + dy[dir];

	if (!isRoute(next_row, next_col)) {
		return -1;
	}

	x = next_row;
	y = next_col;
	roll(dir);

	if (MAP[x][y] == 0) {
		MAP[x][y] = DICE.down;
	}
	else {
		DICE.down = MAP[x][y];
		MAP[x][y] = 0;
	}

	return DICE.up;
}

int main() {
	FASTIO;
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
		}
	}

	int dir;
	while (K--) {
		cin >> dir;
		int current = calc(dir);
		if (current != -1) {
			ans.push_back(current);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}