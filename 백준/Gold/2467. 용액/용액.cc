#include <iostream>
#include <cmath>
#define MAX_SIZE 100001
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define INF 9876543210000

using namespace std;

int N;
long long ARR[MAX_SIZE];
long long left_ans = -1;
long long right_ans = -1;

void calculate() {
	if (ARR[1] >= 0) {
		left_ans = ARR[1];
		right_ans = ARR[2];
		return;
	}
	if (ARR[N] <= 0) {
		left_ans = ARR[N - 1];
		right_ans = ARR[N];
		return;
	}

	int left = 1;
	int right = N;

	long long ans = INF;
	while (true) {
		if (left >= right) break;
		
		if (abs(ARR[left] + ARR[right]) < ans) {
			left_ans = ARR[left];
			right_ans = ARR[right];
			ans = abs(ARR[left] + ARR[right]);
		}

		if (abs(ARR[left]) > abs(ARR[right])) {
			left++;
		}
		else {
			right--;
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> ARR[i];
	}

	calculate();

	cout << left_ans << ' ' << right_ans << endl;
}