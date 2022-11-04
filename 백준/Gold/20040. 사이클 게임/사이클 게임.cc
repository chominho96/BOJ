#include <iostream>
#include <vector>
#define MAX_SIZE 500001
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, m;
int ROOT[MAX_SIZE];
int RANK[MAX_SIZE];
int cnt = 1;
int ans = 0;

void initialize() {
	for (int i = 0; i < MAX_SIZE; i++) {
		ROOT[i] = i;
		RANK[i] = 0;
	}
}

int find(int x) {
	if (ROOT[x] == x) return x;
	else return ROOT[x] = find(ROOT[x]);
}

void union_(int x, int y) {
	x = find(x);
	y = find(y);

	if (x == y) {
		if (ans == 0) ans = cnt;
		return;
	}

	if (RANK[x] < RANK[y]) ROOT[x] = y;
	else {
		ROOT[y] = x;
		if (RANK[x] == RANK[y]) RANK[x]++;
	}
}

int main() {
	FASTIO;
	cin >> n >> m;
	initialize();
	int from, to;
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		union_(from, to);
		cnt++;
	}
	cout << ans << '\n';
}