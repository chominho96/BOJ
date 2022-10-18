#include <iostream>
#include <queue>
#include <string>
#include <set>
#define MAX_SIZE 1001

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
int resultMAP[MAX_SIZE][MAX_SIZE];
int route[1000001];
bool visited[MAX_SIZE][MAX_SIZE];
int N, M;

int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

bool isRoute(int row, int col) {
	return row >= 1 && row <= N && col >= 1 && col <= M;
}

void BFS(int index, int row, int col) {
	queue<int> row_que;
	queue<int> col_que;

	row_que.push(row);
	col_que.push(col);
	visited[row][col] = true;
	MAP[row][col] = index;
	
	int sum = 1;

	while (!row_que.empty()) {
		int current_row = row_que.front();
		int current_col = col_que.front();

		row_que.pop();
		col_que.pop();
		
		for (int count = 0; count < 4; count++) {
			int next_row = current_row + dx[count];
			int next_col = current_col + dy[count];

			if (isRoute(next_row, next_col) && !visited[next_row][next_col] && MAP[next_row][next_col] == 0) {
				MAP[next_row][next_col] = index;
				visited[next_row][next_col] = true;
				row_que.push(next_row);
				col_que.push(next_col);
				sum++;
			}
		}
	}

	route[index] = sum;
}

int main() {
	cin >> N >> M;


	string input;

	for (int i = 1; i <= N; i++) {

		cin >> input;
		for (int j = 1; j <= M; j++) {
			MAP[i][j] = input[j - 1] - '0';
			resultMAP[i][j] = input[j - 1] - '0';
		}
	}

	int index = 2;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 0 && !visited[i][j]) {
				BFS(index, i, j);
				index++;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (resultMAP[i][j] == 1) {

				vector<int> around;

				for (int count = 0; count < 4; count++) {
					int next_row = i + dx[count];
					int next_col = j + dy[count];
					if (isRoute(next_row, next_col) && MAP[next_row][next_col] > 1) {
						around.push_back(MAP[next_row][next_col]);
					}
				}

				for (int count = 0; count < around.size(); count++) {
					bool duplicate = false;
					for (int counter = count - 1; counter >= 0; counter--) {
						if (around[counter] == around[count]) {
							duplicate = true;
						}
					}
					if (!duplicate) {
						resultMAP[i][j] = (resultMAP[i][j] + route[around[count]]) % 10;
					}
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << resultMAP[i][j];
		}
		cout << '\n';
	}
}