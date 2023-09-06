#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 301

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
int N, M, K;

int main() {
	FASTIO;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
		}
	}

	cin >> K;
	int x1, y1, x2, y2;
	vector<int> ans;
	while (K--) {
		cin >> x1 >> y1 >> x2 >> y2;
		
		int current = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (i >= x1 && i <= x2 && j >= y1 && j <= y2) {
					current += MAP[i][j];
				}
			}
		}

		ans.push_back(current);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
}