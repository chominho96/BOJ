#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 1001
#define INF 987654321

using namespace std;

struct first_cost {
	vector<bool> index;
	int cost;
};

int MAP[MAX_SIZE][3];
int DP_1[MAX_SIZE][3];
int DP_2[MAX_SIZE][3];
int DP_3[MAX_SIZE][3];

int main() {
	FASTIO;

	int N, cost;
	cin >> N;

	// input
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost;
			MAP[i][j] = cost;
		}
	}

	
	DP_1[1][0] = INF;
	DP_1[1][1] = MAP[1][1];
	DP_1[1][2] = MAP[1][2];
	DP_2[1][1] = INF;
	DP_2[1][0] = MAP[1][0];
	DP_2[1][2] = MAP[1][2];
	DP_3[1][2] = INF;
	DP_3[1][0] = MAP[1][0];
	DP_3[1][1] = MAP[1][1];

	// DP 1 계산
	for (int i = 2; i < N; i++) {
		DP_1[i][0] = (DP_1[i - 1][1] < DP_1[i - 1][2] ? DP_1[i - 1][1] + MAP[i][0] : DP_1[i - 1][2] + MAP[i][0]);
		DP_1[i][1] = (DP_1[i - 1][0] < DP_1[i - 1][2] ? DP_1[i - 1][0] + MAP[i][1] : DP_1[i - 1][2] + MAP[i][1]);
		DP_1[i][2] = (DP_1[i - 1][0] < DP_1[i - 1][1] ? DP_1[i - 1][0] + MAP[i][2] : DP_1[i - 1][1] + MAP[i][2]);
	}

	// DP 2 계산
	for (int i = 2; i < N; i++) {
		DP_2[i][0] = (DP_2[i - 1][1] < DP_2[i - 1][2] ? DP_2[i - 1][1] + MAP[i][0] : DP_2[i - 1][2] + MAP[i][0]);
		DP_2[i][1] = (DP_2[i - 1][0] < DP_2[i - 1][2] ? DP_2[i - 1][0] + MAP[i][1] : DP_2[i - 1][2] + MAP[i][1]);
		DP_2[i][2] = (DP_2[i - 1][0] < DP_2[i - 1][1] ? DP_2[i - 1][0] + MAP[i][2] : DP_2[i - 1][1] + MAP[i][2]);
	}

	// DP 3 계산
	for (int i = 2; i < N; i++) {
		DP_3[i][0] = (DP_3[i - 1][1] < DP_3[i - 1][2] ? DP_3[i - 1][1] + MAP[i][0] : DP_3[i - 1][2] + MAP[i][0]);
		DP_3[i][1] = (DP_3[i - 1][0] < DP_3[i - 1][2] ? DP_3[i - 1][0] + MAP[i][1] : DP_3[i - 1][2] + MAP[i][1]);
		DP_3[i][2] = (DP_3[i - 1][0] < DP_3[i - 1][1] ? DP_3[i - 1][0] + MAP[i][2] : DP_3[i - 1][1] + MAP[i][2]);
	}

	int min_1 = min(DP_1[N - 1][1], DP_1[N - 1][2]) + MAP[N][0];
	int min_2 = min(DP_2[N - 1][0], DP_2[N - 1][2]) + MAP[N][1];
	int min_3 = min(DP_3[N - 1][0], DP_3[N - 1][1]) + MAP[N][2];

	cout << min(min(min_1, min_2), min_3) << '\n';

}