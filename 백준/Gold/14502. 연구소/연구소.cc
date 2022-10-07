#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 9

using namespace std;

struct row_col {
	int row;
	int col;
};

int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };

int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE]; // 하나의 바이러스에서 BFS 돌 때만 쓰는거
bool onceVisited[MAX_SIZE][MAX_SIZE]; // 총 3번의 BFS에서 돈거
int N, M;
vector<row_col> virus;
vector<row_col> em;
int emNum;
int ans = -1;

void init() {
	for (int i = 1; i < MAX_SIZE; i++) {
		for (int j = 1; j < MAX_SIZE; j++) {
			visited[i][j] = false;
		}
	}
}

void onceInit() {
	for (int i = 1; i < MAX_SIZE; i++) {
		for (int j = 1; j < MAX_SIZE; j++) {
			onceVisited[i][j] = false;
		}
	}
}



bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= M;
}


int BFS(int startRow, int startCol) {
	//cout << "current : " << startRow << ' ' << startCol << endl;

	int answer = 0;
	queue<int> row_que;
	queue<int> col_que;
	
	onceVisited[startRow][startCol] = true;
	row_que.push(startRow);
	col_que.push(startCol);

	while (!row_que.empty()) {
		int current_row = row_que.front();
		int current_col = col_que.front();

		row_que.pop();
		col_que.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_row = current_row + dx[i];
			int next_col = current_col + dy[i];
			if (isRoute(next_row, next_col) && MAP[next_row][next_col] == 0 && !onceVisited[next_row][next_col]) {
				
				if (!visited[next_row][next_col]) {
					answer++;
					visited[next_row][next_col] = true;
				}

				onceVisited[next_row][next_col] = true;
				row_que.push(next_row);
				col_que.push(next_col);
			}
		}
	}

	onceInit();
	return answer;
}

int recursiveCnt = 0;

void recursive(int index, int cnt) {
	if (cnt == 3) {
		/*if (++recursiveCnt > 1000 && recursiveCnt % 1000 == 0) {
			cout << "현재 : " << recursiveCnt << endl;
		}*/
		int currentBFS = 0;
		for (int i = 0; i < virus.size(); i++) {
			currentBFS += BFS(virus[i].row, virus[i].col);
		}
		init();

		if (emNum - currentBFS - 3 > ans) {
			ans = emNum - currentBFS - 3;
		}
		return;
	}

	for (int i = index + 1; i < em.size(); i++) {
		MAP[em[i].row][em[i].col] = 1;
		recursive(i, cnt + 1);
		MAP[em[i].row][em[i].col] = 0;
	}
}


int main() {
	FASTIO;

	cin >> N >> M;

	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> num;
			MAP[i][j] = num;
			if (num == 2) {
				virus.push_back({ i, j });
			}	
			else if (num == 0) {
				em.push_back({ i, j });
				emNum++;
			}
		}
	}

	for (int i = 0; i < em.size(); i++) {
		MAP[em[i].row][em[i].col] = 1;
		recursive(i, 1);
		MAP[em[i].row][em[i].col] = 0;
	}

	cout << ans << '\n';

	
}