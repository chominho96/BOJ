#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 100001

using namespace std;

struct edge {
	int to;
	bool active;
	int idx;
};

int N;
vector<edge> MAP[MAX_SIZE];
int ANS[MAX_SIZE];
bool visited[MAX_SIZE];
int start = -1;
int MIN = 987654321;

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		visited[i] = false;
		ANS[i] = 0;
	}
}

int dfs(int idx) {
	visited[idx] = true;
	int ans = 0;
	for (int i = 0; i < MAP[idx].size(); i++) {
		int next = MAP[idx][i].to;
		if (!visited[next]) {
			if (!MAP[idx][i].active) {
				ANS[MAP[idx][i].idx] = 1;
				ans++;
			}
			ans += dfs(next);
		}
	}
	return ans;
}

void dfs2(int idx, int val) {
	visited[idx] = true;
	if (val < MIN) {
		start = idx;
		MIN = val;
	}
	for (int i = 0; i < MAP[idx].size(); i++) {
		int next = MAP[idx][i].to;
		if (!visited[next]) {
			if (!MAP[idx][i].active) dfs2(next, val - 1);
			else dfs2(next, val + 1);
		}
	}
}

void print() {
	for (int i = 1; i < N; i++) {
		cout << ANS[i];
	}
	cout << endl;
}

int main() {
	FASTIO
	cin >> N;
	for (int i = 1; i < N; i++) {
		int u, v; cin >> u >> v;
		MAP[u].push_back({ v, true, i });
		MAP[v].push_back({ u, false, i });
	}
	int curr = dfs(1);
	init();
	dfs2(1, curr);
	init();
	dfs(start);
	print();
}