#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 110
#define MAX_NUM_SIZE 101

using namespace std;

struct node {
	int number;
	int count;
};

struct compare {
	bool operator()(const node& n1, const node& n2) {
		if (n1.count == n2.count) return n1.number > n2.number;
		return n1.count > n2.count;
	}
};

int r, c, k;
int MAP[MAX_SIZE][MAX_SIZE];
int row_size = 3;
int col_size = 3;

void calc() {

	vector<int> ROW_OR_COL[MAX_SIZE];
	
	if (col_size <= row_size) {		// R 연산

		int new_col_size = -1;

		for (int i = 1; i <= row_size; i++) {
			int NUMBER[MAX_NUM_SIZE]{ 0 };
			priority_queue<node, vector<node>, compare> pq;

			for (int j = 1; j <= col_size; j++) {
				NUMBER[MAP[i][j]]++;
			}

			for (int j = 1; j <= 100; j++) {
				if (NUMBER[j] > 0) {
					pq.push({ j, NUMBER[j] });
				}
			}

			while (!pq.empty()) {
				node current = pq.top();
				pq.pop();
				ROW_OR_COL[i].push_back(current.number);
				ROW_OR_COL[i].push_back(current.count);
			}
			
			//cout << "current: " << ROW_OR_COL[i].size() << endl;
			int size = ROW_OR_COL[i].size();
			
			if (size > new_col_size) {
				new_col_size = size;
			}
		}

		for (int i = 1; i <= row_size; i++) {
			for (int j = 0; j < ROW_OR_COL[i].size(); j++) {
				if (j + 1 > 100) {
					break;
				}
				MAP[i][j + 1] = ROW_OR_COL[i][j];
			}
			for (int j = ROW_OR_COL[i].size() + 1; j <= new_col_size; j++) {
				if (j > 100) {
					break;
				}
				MAP[i][j] = 0;
			}
		}

		if (new_col_size > 100) col_size = 100;
		else col_size = new_col_size;
	}
	else {							// C 연산

		int new_row_size = -1;
		for (int i = 1; i <= col_size; i++) {
			int NUMBER[MAX_NUM_SIZE]{ 0 };
			priority_queue<node, vector<node>, compare> pq;

			for (int j = 1; j <= row_size; j++) {
				NUMBER[MAP[j][i]]++;
			}

			for (int j = 1; j <= 100; j++) {
				if (NUMBER[j] > 0) {
					pq.push({ j, NUMBER[j] });
				}
			}

			while (!pq.empty()) {
				node current = pq.top();
				pq.pop();
				ROW_OR_COL[i].push_back(current.number);
				ROW_OR_COL[i].push_back(current.count);
			}

			int size = ROW_OR_COL[i].size();
			if (size > new_row_size) {
				new_row_size = size;
			}
		}

		for (int i = 1; i <= col_size; i++) {
			for (int j = 0; j < ROW_OR_COL[i].size(); j++) {
				if (j + 1 > 100) {
					break;
				}
				MAP[j + 1][i] = ROW_OR_COL[i][j];
			}
			for (int j = ROW_OR_COL[i].size() + 1; j <= new_row_size; j++) {
				if (j > 100) {
					break;
				}
				MAP[j][i] = 0;
			}
		}

		if (new_row_size > 100) row_size = 100;
		else row_size = new_row_size;
	}
}

int main() {
	FASTIO;
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> MAP[i][j];
		}
	}
	
	for (int i = 0; i <= 100; i++) {
		if (MAP[r][c] == k) {
			cout << i << endl;
			return 0;
		}
		calc();
 	}

	cout << -1 << endl;
}
