#include <iostream>
#include <vector>
#define MAX_SIZE 100001
#define FASTIO ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL)
#define endl '\n'

using namespace std;

int N, R, Q;
vector<int> MAP[MAX_SIZE];
bool visited[MAX_SIZE];
int ANS[MAX_SIZE];

void make_tree(int index) {
	ANS[index]++;
	visited[index] = true;
	for (int i = 0; i < MAP[index].size(); i++) {
		int next = MAP[index][i];
		if (!visited[next]) {
			make_tree(next);
			ANS[index] += ANS[next];
		}
	}
}

int main() {
	FASTIO;
	cin >> N >> R >> Q;
	
	int u, v;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		MAP[u].push_back(v);
		MAP[v].push_back(u);
	}

	make_tree(R);
	
	int q;
	for (int i = 0; i < Q; i++) {
		cin >> q;
		cout << ANS[q] << endl;
	}
}