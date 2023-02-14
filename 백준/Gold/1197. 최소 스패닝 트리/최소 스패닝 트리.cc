#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 10001

using namespace std;

struct edge {
	int to;
	long long value;
};

struct compare {
	bool operator()(const edge& e1, const edge& e2) {
		return e1.value > e2.value;
	}
};

vector<edge> MAP[MAX_SIZE];
int V, E;
long long dist[MAX_SIZE];
bool visited[MAX_SIZE];

int main() {
	FASTIO;
	cin >> V >> E;
	int to, from, value;

	for (int i = 0; i < E; i++) {
		cin >> to >> from >> value;
		MAP[to].push_back({ from, value });
		MAP[from].push_back({ to, value });
	}

	priority_queue<edge, vector<edge>, compare> pq;
	visited[1] = true;
	for (int i = 0; i < MAP[1].size(); i++) {
		pq.push(MAP[1][i]);
	}

	long long ans = 0;
	while (!pq.empty()) {
		edge current = pq.top();
		pq.pop();
		if (visited[current.to]) continue;

		visited[current.to] = true;

		ans += current.value;
		for (int i = 0; i < MAP[current.to].size(); i++) {
			pq.push(MAP[current.to][i]);
		}
	}

	cout << ans << endl;
	
}