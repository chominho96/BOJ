#include <iostream>
#include <utility>
#include <cmath>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 21
#define MAX_STUENT_SIZE 401

using namespace std;

struct node {
	int row;
	int col;
	int empty;
	int like;
};

struct compare {
	bool operator()(const node& n1, const node& n2) {
		if (n1.like == n2.like) {
			if (n1.empty == n2.empty) {
				if (n1.row == n2.row) {
					return n1.col > n2.col;
				}
				return n1.row > n2.row;
			}
			return n1.empty < n2.empty;
		}
		return n1.like < n2.like;
	}
};

int MAP[MAX_SIZE][MAX_SIZE];
bool LIKE[MAX_STUENT_SIZE][MAX_STUENT_SIZE];
int dx[]{ 0, 0, 1, -1 };
int dy[]{ 1, -1, 0, 0 };
int N;

bool isRoute(const int& row, const int& col) {
	return row >= 1 && row <= N && col >= 1 && col <= N;
}

node getNode(const int& student, int row, int col) {
	int like = 0;
	int empty = 0;
	for (int i = 0; i < 4; i++) {
		int next_row = row + dx[i];
		int next_col = col + dy[i];

		if (!isRoute(next_row, next_col)) continue;

		if (LIKE[student][MAP[next_row][next_col]]) {
			like++;
		}
		if (MAP[next_row][next_col] == 0) {
			empty++;
		}
	}
	return { row, col, empty, like };
}

void go(int student) {
	priority_queue<node, vector<node>, compare> pq;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (MAP[i][j] == 0) pq.push(getNode(student, i, j));
		}
	}
	
	MAP[pq.top().row][pq.top().col] = student;
}

int calc() {
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int current = getNode(MAP[i][j], i, j).like;
			ans += pow(10, current - 1);
		}
	}
	return ans;
}

int main() {
	FASTIO;
	cin >> N;

	int student, like;

	for (int i = 0; i < N * N; i++) {
		cin >> student;
		for (int j = 0; j < 4; j++) {
			cin >> like;
			LIKE[student][like] = true;
		}

		go(student);
	}
	cout << calc() << endl;
}