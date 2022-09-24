#include <iostream>
#include <vector>
#include <cmath>
#define MAX_SIZE 100001
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

using namespace std;

vector<int> MAP[MAX_SIZE];
int depth[MAX_SIZE];
int ancestor[MAX_SIZE][20];
int MAX_DEPTH;


void makeTree(int current, int parent) {
	depth[current] = depth[parent] + 1;

	ancestor[current][0] = parent;


	// make ancestor
	for (int i = 1; i <= MAX_DEPTH; i++) {
		int temp = ancestor[current][i - 1];
		ancestor[current][i] = ancestor[temp][i - 1];
	}

	for (int i = 0; i < MAP[current].size(); i++) {
		int next = MAP[current][i];

		if (next != parent) {
			makeTree(next, current);
		}
	}
}

int LCA(int a, int b) {

	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) {
			// b의 depth가 항상 더 크거나 같게 설정
			swap(a, b);
		}

		// b를 끌어올리기
		for (int i = MAX_DEPTH; i >= 0; i--) {
			if (depth[a] <= depth[ancestor[b][i]]) {
				b = ancestor[b][i];
			}
		}
	}

	int lca = a;
	if (a != b) {
		for (int i = MAX_DEPTH; i >= 0; i--) {
			if (ancestor[a][i] != ancestor[b][i]) {
				a = ancestor[a][i];
				b = ancestor[b][i];
			}
			lca = ancestor[a][i];
		}
	}

	return lca;
}

int main() {
	FASTIO;

	MAX_DEPTH = log2(MAX_SIZE);


	int N;
	cin >> N;

	// make MAP
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		MAP[u].push_back(v);
		MAP[v].push_back(u);
	}

	// make TREE
	depth[0] = -1;
	makeTree(1, 0);

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

}