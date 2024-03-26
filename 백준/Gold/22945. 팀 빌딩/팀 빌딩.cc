#include <iostream>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_NUMBER 10001

using namespace std;

int N;
priority_queue<int> MAX_QUEUE[MAX_NUMBER];
priority_queue<int, vector<int>, greater<int>> MIN_QUEUE[MAX_NUMBER];

int calc() {
	int m = 0;
	for (int i = MAX_NUMBER - 1; i >= 1; i--) {
		if (MIN_QUEUE[i].empty()) continue;
		int min1 = MIN_QUEUE[i].top();
		int max1 = MAX_QUEUE[i].top();
		for (int j = i; j < MAX_NUMBER; j++) {
			if (MIN_QUEUE[j].empty()) continue;
			int min2 = MIN_QUEUE[j].top();
			int max2 = MAX_QUEUE[j].top();
			m = max(m, i * (abs(max2 - min1) - 1));
			m = max(m, i *(abs(min2 - max1) - 1));
		}
	}
	return m;
}

int main() {
	FASTIO
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int ab; cin >> ab;
		MAX_QUEUE[ab].push(i);
		MIN_QUEUE[ab].push(i);
	}
	cout << calc() << endl;
}