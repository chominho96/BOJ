#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 21
#define INF 987654321

using namespace std;

struct boundary {
	pair<int, int> left;
	pair<int, int> right;
	pair<int, int> up;
	pair<int, int> down;
};

int MAP[MAX_SIZE][MAX_SIZE];
int N;
vector<boundary> BOUNDARY;
int ans = INF;
int sum = 0;

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= N;
}

void calcBoundary() {
	for (int left_row = 1; left_row <= N; left_row++) {
		for (int left_col = 1; left_col <= N; left_col++) {

			int up_row = left_row - 1;
			int up_col = left_col + 1;

			while (true) {
				if (!isRoute(up_row, up_col)) break;

				int down_row = left_row + 1;
				int down_col = left_col + 1;
				int right_row = up_row + 1;
				int right_col = up_col + 1;
				while (true) {
					if (!isRoute(down_row, down_col) || !isRoute(right_row, right_col)) break;

					BOUNDARY.push_back({ { left_row, left_col }, { right_row, right_col }, { up_row, up_col }, { down_row, down_col } });
					
					down_row++;
					down_col++;
					right_row++;
					right_col++;
				}

				up_row--;
				up_col++;
			}
		}
	}
}

void calc(int idx) {
	
	pair<int, int> left = BOUNDARY[idx].left;
	pair<int, int> right = BOUNDARY[idx].right;
	pair<int, int> up = BOUNDARY[idx].up;
	pair<int, int> down = BOUNDARY[idx].down;

	int current_sum = 0;
	int area1 = 0, area2 = 0, area3 = 0, area4 = 0, area5 = 0;

	// 직사각형 영역 구하기
	for (int i = 1; i <= up.first - 1; i++) {
		for (int j = 1; j <= up.second; j++) {
			area1 += MAP[i][j];
		}
		for (int j = up.second + 1; j <= N; j++) {
			area2 += MAP[i][j];
		}
	}
	for (int i = down.first + 1; i <= N; i++) {
		for (int j = 1; j <= down.second - 1; j++) {
			area3 += MAP[i][j];
		}
		for (int j = down.second; j <= N; j++) {
			area4 += MAP[i][j];
		}
	}

	// 1. 1 구하기
	int length = up.second - 1;
	for (int i = up.first; i <= left.first - 1; i++) {
		for (int j = 1; j <= length; j++) {
			area1 += MAP[i][j];
		}
		length--;
	}
	current_sum += area1;
	// 2. 2 구하기
	length = N - up.second;
	for (int i = up.first; i <= right.first; i++) {
		for (int j = N; j > N - length; j--) {
			area2 += MAP[i][j];
		}
		length--;
	}
	current_sum += area2;
	// 3. 3 구하기
	length = left.second - 1;
	for (int i = left.first; i <= down.first; i++) {
		for (int j = 1; j <= length; j++) {
			area3 += MAP[i][j];
		}
		length++;
	}
	current_sum += area3;
	// 4. 4 구하기
	length = N - down.second;
	for (int i = down.first; i >= right.first + 1; i--) {
		for (int j = N; j > N - length; j--) {
			area4 += MAP[i][j];
		}
		length--;
	}
	current_sum += area4;
	// 5. 전체 구하고 5 구하기
	area5 = sum - current_sum;

	int current = max(max(max(max(area1, area2), area3), area4), area5) - min(min(min(min(area1, area2), area3), area4), area5);
	if (current < ans) ans = current;
}

int main() {
	FASTIO;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			sum += MAP[i][j];
		}
	}

	calcBoundary();

	for (int i = 0; i < BOUNDARY.size(); i++) {
		calc(i);
	}

	cout << ans << endl;
}