#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 1001
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, M;
int DEPTH[MAX_SIZE];
vector<int> MAP[MAX_SIZE];

int main() {
	FASTIO;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int T; cin >> T;
		vector<int> vec(T);
		for (int j = 0; j < T; j++) {
			cin >> vec[j];
		}
		
		for (int j = 0; j < T - 1; j++) {
			MAP[vec[j]].push_back(vec[j + 1]);
			DEPTH[vec[j + 1]]++;
		}
	}

	queue<int> que;
	for (int i = 1; i <= N; i++) {
		if (DEPTH[i] == 0) {
			que.push(i);
		}
	}


	vector<int> ans;

	while (!que.empty()) {
		int current = que.front();
		que.pop();
		ans.push_back(current);
		
		for (int i = 0; i < MAP[current].size(); i++) {
			int next = MAP[current][i];

			DEPTH[next]--;
			if (DEPTH[next] == 0) {
				que.push(next);
			}			
			
		}
	}

	if (ans.size() != N) cout << "0\n";
	else {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}
	}

}