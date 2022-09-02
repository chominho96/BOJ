#include <iostream>
#include <queue>

using namespace std;

int main() {

	int N, input;
	cin >> N;

	priority_queue<int> greaterPq;
	priority_queue<int, vector<int>, greater<int>> lowerPq;

	for (int i = 0; i < N; i++) {
		cin >> input;
		greaterPq.push(input);
	}
	for (int i = 0; i < N; i++) {
		cin >> input;
		lowerPq.push(input);
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		ans += greaterPq.top() * lowerPq.top();
		greaterPq.pop();
		lowerPq.pop();
	}

	cout << ans << '\n';
		



	
}