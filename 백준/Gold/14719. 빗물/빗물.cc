#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 501

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
int dx[]{ 0, 1 };
int dy[]{ -1, 0 };
int H, W;

int main() {
	FASTIO;
	cin >> H >> W;

	int h;
	for (int i = 1; i <= W; i++) {
		cin >> h;
		for (int j = 1; j <= h; j++) {
			MAP[j][i] = 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= H; i++) {

		int left = -1;
		int right = -1;

		for (int j = 1; j <= W; j++) {
			if (MAP[i][j] == 1) {
				left = j;
				break;
			}
		}
		for (int j = W; j >= 1; j--) {
			if (MAP[i][j] == 1) {
				right = j;
				break;
			}
		}
	
		if (left != -1) {
			for (int j = left + 1; j < right; j++) {
				if (MAP[i][j] == 0) ans++;
			}
		}
	}

	cout << ans << endl;
	
}