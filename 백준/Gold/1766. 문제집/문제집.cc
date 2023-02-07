#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false);
#define endl '\n'
#define MAX_SIZE 32001

using namespace std;

int N, M;
vector<int> MAP[MAX_SIZE];
int INCOME[MAX_SIZE];

int main() {
	FASTIO;
	cin >> N >> M;
	
	int from, to;
	for (int i = 0; i < M; i++) {
		cin >> from >> to;
		MAP[from].push_back(to);
		INCOME[to]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (INCOME[i] == 0) {
			pq.push(i);
		}
	}

	while (!pq.empty()) {
		int current = pq.top();
		cout << current << ' ';
		pq.pop();
		
		for (int i = 0; i < MAP[current].size(); i++) {
			int next = MAP[current][i];
			INCOME[next]--;
			if (INCOME[next] == 0) {
				pq.push(next);
			}
		}
	}
	cout << endl;
}