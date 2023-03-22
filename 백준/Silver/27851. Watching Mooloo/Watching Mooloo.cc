#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 100001

using namespace std;

long long N, K;
long long DAY[MAX_SIZE];

int main() {
	FASTIO;
	cin >> N >> K;
	
	for (int i = 1; i <= N; i++) {
		cin >> DAY[i];
	}

	long long result = 0;
	long long current = 0;
	for (int i = 1; i <= N; i++) {
		if (current == 0 || DAY[i] - DAY[i - 1] > K + 1) {
			result += current;
			current = K + 1;
		}
		else {
			current += DAY[i] - DAY[i - 1];
		}
	}
	result += current;

	cout << result << endl;
	
}