#include <iostream>
#define MAX_SIZE 100001
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define INF 987654321

using namespace std;

long long N, S;
long long ARR[MAX_SIZE];
long long sum = 0;

int calculate() {
	if (sum < S) return 0;

	int left = 1;
	int right = 1;
	int ans = INF;
	long long current_sum = ARR[1];
	int current_len = 1;

	while (true) {
		if (right > N) break;
		
		if (current_sum >= S) {
			if (left == right) return 1;
			// left 늘리기
			current_sum -= ARR[left++];

			if (current_len < ans) ans = current_len;
			current_len--;
		}
		else {
			// right 늘리기
			current_sum += ARR[++right];
			current_len++;
		}
	}

	/*for (int i = left; i <= right; i++) {
		cout << ARR[i] << ' ';
	}
	cout << endl;*/

	return ans;
}

int main() {
	FASTIO;
	cin >> N >> S;

	for (int i = 1; i <= N; i++) {
		cin >> ARR[i];
		sum += ARR[i];
	}

	cout << calculate() << endl;
}