#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 13

using namespace std;

/*
* [dir]
* 1: 오른쪽
* 2: 왼쪽
* 3: 위쪽
* 4: 아래쪽
*/

struct HORSE {
	int index;
};

struct HORSE_POS {
	int dir;
	int row;
	int col;
};

struct node {
	int color;
	vector<HORSE> horse;
};

node MAP[MAX_SIZE][MAX_SIZE];
HORSE_POS HORSE_POS_MAP[MAX_SIZE];
int N, K;
int dx[]{ 0, 0, 0, -1, 1 };
int dy[]{ 0, 1, -1, 0, 0 };

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= N;
}

void move(int row, int col, int next_row, int next_col, int index) {
	bool flag = false;
	for (int i = 0; i < MAP[row][col].horse.size(); i++) {
		HORSE current = MAP[row][col].horse[i];
		if (flag) {
			HORSE_POS_MAP[current.index].row = next_row;
			HORSE_POS_MAP[current.index].col = next_col;
			MAP[next_row][next_col].horse.push_back(current);
		}
		else {
			if (current.index == index) {
				flag = true;
				HORSE_POS_MAP[current.index].row = next_row;
				HORSE_POS_MAP[current.index].col = next_col;
				MAP[next_row][next_col].horse.push_back(current);
			}
		}
	}
	
	while (true) {
		int size = MAP[row][col].horse.size();
		if (MAP[row][col].horse[size - 1].index == index) {
			MAP[row][col].horse.pop_back();
			break;
		}
		MAP[row][col].horse.pop_back();
	}
}

bool go(int index) {

	int row = HORSE_POS_MAP[index].row;
	int col = HORSE_POS_MAP[index].col;

	int next_row = row + dx[HORSE_POS_MAP[index].dir];
	int next_col = col + dy[HORSE_POS_MAP[index].dir];

	// 파랑색 or 길이 아닌 경우
	if (!isRoute(next_row, next_col) || MAP[next_row][next_col].color == 2) {

		if (HORSE_POS_MAP[index].dir == 1) HORSE_POS_MAP[index].dir = 2;
		else if (HORSE_POS_MAP[index].dir == 2) HORSE_POS_MAP[index].dir = 1;
		else if (HORSE_POS_MAP[index].dir == 3) HORSE_POS_MAP[index].dir = 4;
		else if (HORSE_POS_MAP[index].dir == 4) HORSE_POS_MAP[index].dir = 3;

		next_row = row + dx[HORSE_POS_MAP[index].dir];
		next_col = col + dy[HORSE_POS_MAP[index].dir];
	}
	
	// 방향을 바꿔도 파랑색이거나 맵 밖으로 나갈 경우
	if (!isRoute(next_row, next_col) || MAP[next_row][next_col].color == 2) {

	}

	// 흰색
	else if (MAP[next_row][next_col].color == 0) {
		move(row, col, next_row, next_col, index);
	}

	// 빨간색
	else {
		while (true) {
			int size = MAP[row][col].horse.size();
			if (MAP[row][col].horse[size - 1].index == index) {
				HORSE_POS_MAP[MAP[row][col].horse[size - 1].index].row = next_row;
				HORSE_POS_MAP[MAP[row][col].horse[size - 1].index].col = next_col;
				MAP[next_row][next_col].horse.push_back(MAP[row][col].horse[size - 1]);
				MAP[row][col].horse.pop_back();
				break;
			}

			HORSE_POS_MAP[MAP[row][col].horse[size - 1].index].row = next_row;
			HORSE_POS_MAP[MAP[row][col].horse[size - 1].index].col = next_col;
			MAP[next_row][next_col].horse.push_back(MAP[row][col].horse[size - 1]);
			MAP[row][col].horse.pop_back();
		}
	}

	// game over 판단
	if (isRoute(next_row, next_col) && MAP[next_row][next_col].horse.size() >= 4) {
		return true;
	}
	
	return false;
}

int main() {
	FASTIO;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j].color;
		}
	}

	for (int i = 1; i <= K; i++) {
		cin >> HORSE_POS_MAP[i].row >> HORSE_POS_MAP[i].col >> HORSE_POS_MAP[i].dir;
		MAP[HORSE_POS_MAP[i].row][HORSE_POS_MAP[i].col].horse.push_back({ i });
	}

	int turn = 1;
	while (true) {
		if (turn > 1000) {
			break;
		}
		
		for (int i = 1; i <= K; i++) {
			if (go(i)) {
				cout << turn << endl;
				return 0;
			}
		}
		turn++;
	}

	cout << -1 << endl;
}