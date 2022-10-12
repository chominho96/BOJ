#include <iostream>
#include <queue>
#include <vector>
#define MAX_SIZE 1000001

using namespace std;

int DP[MAX_SIZE];
bool visited[MAX_SIZE];
int N;

void calculate() {

	queue<int> que;
	DP[1] = 0;
	
	visited[1] = true;
	que.push(1);

	while (!que.empty()) {
		int current = que.front();
		que.pop();
		if (current == N) {
			break;
		}
		
		if (current + 1 <= N && !visited[current + 1]) {
			DP[current + 1] = current;
			visited[current + 1] = true;
			que.push(current + 1);
		}
		if (current * 2 <= N && !visited[current * 2]) {
			DP[current * 2] = current;
			visited[current * 2] = true;
			que.push(current * 2);
		}
		if (current * 3 <= N && !visited[current * 3]) {
			DP[current * 3] = current;
			visited[current * 3] = true;
			que.push(current * 3);
		}
	}

	
}

int main() {
	cin >> N;
	calculate();

	int ans = 0;
	int index = N;

	vector<int> ansVec;
	while (true) {
		ansVec.push_back(index);
		
		if (index == 1) {
			break;
		}

		ans++;
		index = DP[index];
	}
	
	cout << ans << '\n';
	for (int i = 0; i < ansVec.size(); i++) {
		cout << ansVec[i] << ' ';
	}
	cout << '\n';
}