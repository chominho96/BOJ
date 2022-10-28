#include <iostream>
#include <vector>
#include <queue>
#define MAX_SIZE 32001
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int M, N;

int DEPTH[MAX_SIZE];
vector<int> MAP[MAX_SIZE];
bool visited[MAX_SIZE];

int main() {
	FASTIO;
	cin >> N >> M;

	int A, B;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		DEPTH[B]++;
		MAP[A].push_back(B);
	}
	
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (DEPTH[i] == 0) {
			visited[i] = true;
			que.push(i);
		}
	}

	while (!que.empty()) {
		int current = que.front();
		que.pop();
		cout << current << ' ';
		for (int i = 0; i < MAP[current].size(); i++) {
			int next = MAP[current][i];

			if (!visited[next]) {
				DEPTH[next]--;
				if (DEPTH[next] == 0) {
					visited[next] = true;
					que.push(next);
				}
			}
			
		}
		
	}
	cout << '\n';
}