#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 51
#define INF 987654321

using namespace std;

int N, M;
int MAP[MAX_SIZE][MAX_SIZE];
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
bool isExist[MAX_SIZE][MAX_SIZE];
int ans = INF;

int dist() {

	int totalAns = 0;

	for (int k = 0; k < houses.size(); k++) {
		int row = houses[k].first;
		int col = houses[k].second;

		int singleAns = INF;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (MAP[i][j] == 2 && isExist[i][j] && abs(i - row) + abs(j - col) < singleAns) {
					singleAns = abs(i - row) + abs(j - col);
				}
			}
		}
		totalAns += singleAns;
	}

	return totalAns;
}

void calc(int idx, int cnt) {
	
	if (cnt == M) {
		int current = dist();
		if (current < ans) ans = current;
		return;
	}
	
	for (int i = idx + 1; i < chickens.size(); i++) {
		isExist[chickens[i].first][chickens[i].second] = true;
		calc(i, cnt + 1);
		isExist[chickens[i].first][chickens[i].second] = false;
	}
}

int main() {
	
	FASTIO;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 1) houses.push_back({ i, j });
			else if (MAP[i][j] == 2) chickens.push_back({ i, j });
		}
	}

	for (int i = 0; i < chickens.size(); i++) {
		isExist[chickens[i].first][chickens[i].second] = true;
		calc(i, 1);
		isExist[chickens[i].first][chickens[i].second] = false;
	}

	cout << ans << endl;
}