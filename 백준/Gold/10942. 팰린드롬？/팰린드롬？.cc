#include <iostream>
#include <vector>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 2001

using namespace std;

int NUM[MAX_SIZE];
int palindrome[MAX_SIZE][MAX_SIZE];
int N, M, S, E;

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		palindrome[i][i] = 1;
	}
}

void calc(const int& idx) {

	int leftIdx = idx - 1;
	int rightIdx = idx + 1;

	while (true) {
		if (leftIdx <= 0 || rightIdx > N) break;

		if (NUM[leftIdx] == NUM[rightIdx]) {
			palindrome[leftIdx][rightIdx] = 1;
			palindrome[rightIdx][leftIdx] = 1;

			leftIdx--;
			rightIdx++;
		}
		else {
			break;
		}
	}

	leftIdx = idx;
	rightIdx = idx + 1;

	while (true) {
		if (leftIdx <= 0 || rightIdx > N) return;

		if (NUM[leftIdx] == NUM[rightIdx]) {
			palindrome[leftIdx][rightIdx] = 1;
			palindrome[rightIdx][leftIdx] = 1;

			leftIdx--;
			rightIdx++;
		}
		else {
			return;
		}
	}
}

int main() {
	FASTIO;
	init();
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> NUM[i];
	}

	for (int i = 1; i <= N; i++) {
		calc(i);
	}

	cin >> M;
	vector<pair<int, int>> question;

	for (int i = 0; i < M; i++) {
		cin >> S >> E;
		question.push_back({ S, E });
		
	}
	for (int i = 0; i < M; i++) {
		cout << palindrome[question[i].first][question[i].second] << endl;
	}
}