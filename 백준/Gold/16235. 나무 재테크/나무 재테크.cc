#include <iostream>
#include <deque>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 11

using namespace std;

struct node {
	deque<int> tree;
	int food = 0;
};

int N, M, K;
int FOOD[MAX_SIZE][MAX_SIZE];
node MAP[MAX_SIZE][MAX_SIZE];
int dx[]{ 0, 0, 1, 1, 1, -1, -1, -1 };
int dy[]{ 1, -1, 0, 1, -1, 0, 1, -1 };

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= N;
}

void calc() {

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {

			// 1. 나무 양분 먹기
			int dead = 0;
			int current_size = MAP[i][j].tree.size();
			
			for (int k = 0; k < current_size; k++) {
				int current = MAP[i][j].tree.front();
				MAP[i][j].tree.pop_front();

				if (MAP[i][j].food >= current) {
					MAP[i][j].food -= current;
					MAP[i][j].tree.push_back(current + 1);
				}
				else {
					dead += current / 2;
				}
			}

			// 2. 죽은 나무 먹기
			MAP[i][j].food += dead;
		}
	}

	// 3. 나무 번식
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int current : MAP[i][j].tree) {
				if (current % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int next_row = i + dx[k];
						int next_col = j + dy[k];

						if (isRoute(next_row, next_col)) {
							MAP[next_row][next_col].tree.push_front(1);
						}
					}
				}
			}
		}
	}

	// 4. 양분 더하기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			MAP[i][j].food += FOOD[i][j];
		}
	}

}

int calcAns() {
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += MAP[i][j].tree.size();
		}
	}
	return ans;
}

int main() {
	FASTIO;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> FOOD[i][j];
			MAP[i][j].food = 5;
		}
	}

	int x, y, age;
	while (M--) {
		cin >> x >> y >> age;
		MAP[x][y].tree.push_back(age);
	}
	
	while (K--) {
		calc();
	}

	cout << calcAns() << endl;
}