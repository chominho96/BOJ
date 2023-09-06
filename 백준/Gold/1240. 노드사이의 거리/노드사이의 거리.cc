#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 1001

using namespace std;

vector<pair<int, int>> MAP[MAX_SIZE];
bool visited[MAX_SIZE];
int N, M;

int DIST[MAX_SIZE][MAX_SIZE];

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		visited[i] = false;
	}
}

int bfs(int node, int find) {
	init();
	queue<pair<int, int>> que;
	que.push({ node, 0 });
	visited[node] = true;

	while (!que.empty()) {
		int current = que.front().first;
		int value = que.front().second;

		que.pop();

		for (int i = 0; i < MAP[current].size(); i++) {
			int next = MAP[current][i].first;
			int next_value = MAP[current][i].second;

			if (next == find) {
				DIST[node][find] = value + next_value;
				DIST[find][node] = value + next_value;
				return value + next_value;
			}

			if (!visited[next]) {
				visited[next] = true;
				que.push({ next, value + next_value });
			}
		}
	}

	return -1;
}

int main() {
	FASTIO;
	cin >> N >> M;

	int x, y, dist;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y >> dist;
		MAP[x].push_back({ y, dist });
		MAP[y].push_back({ x, dist });
	}

	int node, find;
	vector<int> answer;
	while (M--) {
		cin >> node >> find;
		if (node == find) {
			answer.push_back(0);
		}
		else if (DIST[node][find] != 0) {
			answer.push_back(DIST[node][find]);
		}
		else {
			answer.push_back(bfs(node, find));
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}