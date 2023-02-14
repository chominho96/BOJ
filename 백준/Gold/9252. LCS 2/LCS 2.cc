#include <iostream>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 1001

using namespace std;

int DP[MAX_SIZE][MAX_SIZE];

string A, B;
int ans = 0;
int max_value;
string ans_str = "";

void backtrack(int i, int j) {
	if (i == 0 || j == 0) return;
	if (A[i - 1] == B[j - 1] && DP[i][j] == max_value) {
		ans_str = A[i - 1] + ans_str;
		max_value--;
		backtrack(i - 1, j - 1);
	}
	else if (DP[i - 1][j] == DP[i][j]) {
		backtrack(i - 1, j);
	}
	else if (DP[i][j - 1] == DP[i][j]) {
		backtrack(i, j - 1);
	}
}

int main() {
	FASTIO;
	cin >> A >> B;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < B.size(); j++) {
			if (A[i] == B[j]) {
				DP[i + 1][j + 1] = DP[i][j] + 1;

				if (DP[i + 1][j + 1] > ans) {
					ans = DP[i + 1][j + 1];
				}
			}
			else {
				if (DP[i][j + 1] > DP[i + 1][j]) {
					DP[i + 1][j + 1] = DP[i][j + 1];
				}
				else {
					DP[i + 1][j + 1] = DP[i + 1][j];
				}
			}
		}
	}

	max_value = ans;
	backtrack(A.size(), B.size());

	cout << ans << endl << ans_str << endl;
}