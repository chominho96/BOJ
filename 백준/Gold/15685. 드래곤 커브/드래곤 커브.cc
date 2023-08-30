#include <iostream>
#include <cmath>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 101

using namespace std;

struct node {
	int x;
	int y;
	int dir;
};

int N;
bool MAP[MAX_SIZE][MAX_SIZE];
int dx[]{ 1, 0, -1, 0 };
int dy[]{ 0, -1, 0, 1 };
int ddir[]{ 1, 2, 3, 0 };

/*
* [dir]
* 0: x 증가 -> 1
* 1: y 감소 -> 2
* 2: x 감소 -> 3
* 3: y 증가 -> 0
*/


void dragon(int x, int y, int dir, int gen) {

	vector<int> dirVec;

	dirVec.push_back(dir);

	while (gen--) {
		int size = dirVec.size() - 1;
		for (int i = size; i >= 0; i--) {
			dirVec.push_back(ddir[dirVec[i]]);
		}
	}

	MAP[x][y] = true;
	for (int i = 0; i < dirVec.size(); i++) {
		x += dx[dirVec[i]];
		y += dy[dirVec[i]];
		MAP[x][y] = true;
	}
}

int calc() {

	int ans = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (MAP[i][j] && MAP[i + 1][j] && MAP[i][j + 1] && MAP[i + 1][j + 1]) ans++;
		}
	}

	return ans;
}

int main() {

	FASTIO;
	cin >> N;

	int x, y, d, g;
	while (N--) {
		cin >> x >> y >> d >> g;
		dragon(x, y, d, g);
	}

	cout << calc() << endl;
}