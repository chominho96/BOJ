#include <iostream>
#include <string>
#include <queue>
#define MAX_SIZE 101

using namespace std;

char MAP[MAX_SIZE][MAX_SIZE];
bool key[27];
// num of alphabet is 26
// key[1] means whether there is A's key(a)
bool visited[MAX_SIZE][MAX_SIZE];
int result = 0;

int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

struct row_col {
	int row;
	int col;
};

void initialize(int row_size, int col_size) {
	for (int index = 1; index < 27; index++) {
		key[index] = false;
	}
	for (int i = 1; i <= row_size; i++) {
		for (int j = 1; j <= col_size; j++) {
			visited[i][j] = false;
		}
	}
	result = 0;
}

bool isRoute(int row, int col, int row_size, int col_size) {
	if (row >= 1 && row <= row_size && col >= 1 && col <= col_size) {
		return true;
	}
	return false;
}


void BFS(int start_row, int start_col, int row_size, int col_size, queue<row_col>& que) {
	queue<int> row_que;
	queue<int> col_que;
	row_que.push(start_row);
	col_que.push(start_col);
	visited[start_row][start_col] = true;


	while (!row_que.empty()) {
		int current_row = row_que.front();
		int currrent_col = col_que.front();

		row_que.pop();
		col_que.pop();

		if (MAP[current_row][currrent_col] == '$') {
			result++;
		}


		for (int count = 0; count < 4; count++) {
			int next_row = current_row + dx[count];
			int next_col = currrent_col + dy[count];

			if (isRoute(next_row, next_col, row_size, col_size) && !visited[next_row][next_col]) {
				// 1. route or document or key
				if (MAP[next_row][next_col] == '.' || MAP[next_row][next_col] == '$') {
					row_que.push(next_row);
					col_que.push(next_col);
					visited[next_row][next_col] = true;
				}
				else if (MAP[next_row][next_col] >= 'a' && MAP[next_row][next_col] <= 'z') {
					key[MAP[next_row][next_col] - 96] = true;
					MAP[next_row][next_col] = '.';
					row_que.push(next_row);
					col_que.push(next_col);
					visited[next_row][next_col] = true;
				}

				// 2. wall that can be broken
				else if (MAP[next_row][next_col] != '*') {

					if (key[MAP[next_row][next_col] - 64]) {
						// if already has key
						MAP[next_row][next_col] = '.';
						row_que.push(next_row);
						col_que.push(next_col);
						visited[next_row][next_col] = true;
					}
					else {
						// if there is no key currently
						que.push(row_col{ next_row, next_col });
					}
				}

			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, h, w;
	string input_str;

	cin >> T;

	for (int count = 0; count < T; count++) {

		// input
		cin >> h >> w;
		for (int i = 1; i <= h; i++) {
			cin >> input_str;
			for (int j = 1; j <= w; j++) {
				char input = input_str[j - 1];
				MAP[i][j] = input;
				// make key
			}
		}
		cin >> input_str;
		if (input_str != "0") {
			for (int index = 0; index < input_str.size(); index++) {
				key[input_str[index] - 96] = true;
			}
		}
		

		// store door
		queue<row_col> que;
		
		
		// DFS
		for (int i = 1; i <= h; i++) {
			if (i == 1 || i == h) {
				for (int j = 1; j <= w; j++) {
					if (!visited[i][j]) {
						if (MAP[i][j] == '.' || MAP[i][j] == '$') {
							BFS(i, j, h, w, que);
						}
						else if (MAP[i][j] >= 'a' && MAP[i][j] <= 'z') {
							key[MAP[i][j] - 96] = true;
							BFS(i, j, h, w, que);
						}
						else if (MAP[i][j] >= 'A' && MAP[i][j] <= 'Z') {
							if (key[MAP[i][j] - 64]) {
								MAP[i][j] = '.';
								BFS(i, j, h, w, que);
							}
							else {
								que.push(row_col{ i, j });
							}
						}
					}
					
				}
			}
			else {
				if (!visited[i][1]) {
					if (MAP[i][1] == '.' || MAP[i][1] == '$') {
						BFS(i, 1, h, w, que);
					}
					else if (MAP[i][1] >= 'a' && MAP[i][1] <= 'z') {
						key[MAP[i][1] - 96] = true;
						BFS(i, 1, h, w, que);
					}
					else if (MAP[i][1] >= 'A' && MAP[i][1] <= 'Z') {
						if (key[MAP[i][1] - 64]) {
							MAP[i][1] = '.';
							BFS(i, 1, h, w, que);
						}
						else {
							que.push(row_col{ i, 1 });
						}
					}
				}
				

				if (!visited[i][w]) {
					if (MAP[i][w] == '.' || MAP[i][w] == '$') {
						BFS(i, w, h, w, que);
					}
					else if (MAP[i][w] >= 'a' && MAP[i][w] <= 'z') {
						key[MAP[i][w] - 96] = true;
						BFS(i, w, h, w, que);
					}
					else if (MAP[i][w] >= 'A' && MAP[i][w] <= 'Z') {
						if (key[MAP[i][w] - 64]) {
							MAP[i][w] = '.';
							BFS(i, w, h, w, que);
						}
						else {
							que.push(row_col{ i, w });
						}
					}
				}
				
			}
		}

		// door
		// 독립적인 큐를 만들어서 썼다 지웠다 썼다 지웠다를 해야함
		int broke_num = -1;

		while (broke_num != 0) {
			queue<row_col> que_2;
			broke_num = 0;

			while (!que.empty()) {
				int current_row = que.front().row;
				int current_col = que.front().col;

				que.pop();
				if (!visited[current_row][current_col] && key[MAP[current_row][current_col] - 64]) {
					BFS(current_row, current_col, h, w, que_2);
					broke_num++;
				}
				else {
					que_2.push(row_col{ current_row, current_col });
				}
			}
			que = que_2;
		}



		cout << result << "\n";
		initialize(h, w);
	}
}
