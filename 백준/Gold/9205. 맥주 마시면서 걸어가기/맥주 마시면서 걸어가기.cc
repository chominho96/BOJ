#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 105

using namespace std;

vector<int> MAP[MAX_SIZE];
bool visited[MAX_SIZE];
int n;
int COORD[MAX_SIZE][2];

void BFS() {
	queue<int> que;
	visited[1] = true;
	que.push(1);

	while (!que.empty()) {
		int current = que.front();
		que.pop();

		for (int i = 0; i < MAP[current].size(); i++) {
			int next = MAP[current][i];

			if (next == n + 2) {
				cout << "happy" << endl;
				return;
			}

			if (!visited[next]) {
				visited[next] = true;
				que.push(next);
			}
		}
	}

	cout << "sad" << endl;
}

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		MAP[i].clear();
		visited[i] = false;
	}
}

int main() {
	FASTIO;
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n + 2; i++) {
			cin >> COORD[i][0] >> COORD[i][1];
		}

		// make map
		for (int i = 1; i <= n + 2; i++) {
			for (int j = i + 1; j <= n + 2; j++) {
				int dist = abs(COORD[i][0] - COORD[j][0]) + abs(COORD[i][1] - COORD[j][1]);

				if (dist <= 1000) {
					MAP[i].push_back(j);
					MAP[j].push_back(i);
				}
			}
		}

		BFS();
		init();
	}
}