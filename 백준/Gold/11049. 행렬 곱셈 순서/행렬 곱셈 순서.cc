#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 504
#define INF 987654321

using namespace std;

int MAP[MAX_SIZE][2];
int DP[MAX_SIZE][MAX_SIZE][3];

int main() {
	FASTIO;
	int N, r, c;
	cin >> N;

	
	for (int i = 1; i <= N; i++) {
		cin >> r >> c;
		MAP[i][0] = r;
		MAP[i][1] = c;
	}

	// 1. DP 초기화
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			DP[i][j][0] = INF;
		}
	}

	for (int i = 1; i <= N; i++) {
		DP[i][1][1] = MAP[i][0];
		DP[i][1][2] = MAP[i][1];
		DP[i][1][0] = 0;
	}

	// 2. DP 계산
	for (int i = 1; i <= N - 1; i++) {

		for (int j = 1; j <= N; j++) {
			// i개를 다루되, 현재 i 덩어리의 시작 위치는 j
			for (int k = 1; k <= i; k++) {
				// 현재 가리키고 있는 i 덩어리의 앞뒤로 다 계산
				if (i + j - 1 + k <= N) {
					// 뒤
					int current_row = DP[j][i][1];
					int current_col = DP[i + j][k][2];
					int current_ans = DP[j][i][0] + DP[i + j][k][0] + current_row * current_col * DP[j][i][2];
					if (current_ans < DP[j][i + k][0]) {
						DP[j][i + k][0] = current_ans;
						DP[j][i + k][1] = current_row;
						DP[j][i + k][2] = current_col;
					}
				}
				if (j - k >= 1) {
					// 앞
					int current_row = DP[j - k][k][1];
					int current_col = DP[j][i][2];
					int current_ans = DP[j - k][k][0] + DP[j][i][0] + current_row * current_col * DP[j - k][k][2];
					if (current_ans < DP[j - k][i + k][0]) {
						DP[j - k][i + k][0] = current_ans;
						DP[j - k][i + k][1] = current_row;
						DP[j - k][i + k][2] = current_col;
					}
				}
			}
		}
	}

	cout << DP[1][N][0] << '\n';
	

}