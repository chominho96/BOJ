#include <iostream>
#include <queue>
#define MAX_SIZE 100001

using namespace std;

int DP[MAX_SIZE];
bool visited[MAX_SIZE];
int N, K;

void BFS() {
	queue<int> que;
	que.push(N);
	visited[N] = true;
	DP[N] = 0;

	while (!que.empty()) {
		int current = que.front();
		que.pop();
		if (current == K) {
			cout << DP[K] << endl;
			exit(0);
		}


		// case 1
		if (current - 1 >= 0 && !visited[current - 1]) {
			DP[current - 1] = DP[current] + 1;
			visited[current - 1] = true;
			que.push(current - 1);
		}
		
		// case 2
		if (current + 1 < MAX_SIZE && !visited[current + 1]) {
			DP[current + 1] = DP[current] + 1;
			visited[current + 1] = true;
			que.push(current + 1);
		}

		// case 3
		if (current * 2 < MAX_SIZE && !visited[current * 2]) {
			DP[current * 2] = DP[current] + 1;
			visited[current * 2] = true;
			que.push(current * 2);
		}
		
	}

}

int main() {
	cin >> N >> K;
	BFS();
}