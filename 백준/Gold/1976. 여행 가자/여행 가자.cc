#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 201

using namespace std;

vector<int> MAP[MAX_SIZE];
int CONNECT[MAX_SIZE];
int CONNNECT_INDEX = 1;
bool vistied[MAX_SIZE];
int N, M;
int ORDER[1001];

void DFS(int index) {
	if (vistied[index]) return;

	vistied[index] = true;
	CONNECT[index] = CONNNECT_INDEX;
	
	for (int i = 0; i < MAP[index].size(); i++) {
		DFS(MAP[index][i]);
	}
}

int main() {
	FASTIO;
	cin >> N >> M;

	int connect;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> connect;
			if (connect == 1) {
				MAP[i].push_back(j);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		DFS(i);
		CONNNECT_INDEX++;
	}

	for (int i = 0; i < M; i++) {
		cin >> ORDER[i];
	}
	for (int i = 0; i < M - 1; i++) {
		if (CONNECT[ORDER[i]] != CONNECT[ORDER[i + 1]]) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

}