#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 1000001
#define MAX_NUMBER_SIZE 100001

using namespace std;

int SCORE[MAX_SIZE];
bool visited[MAX_SIZE];
int N;

void calc(const int& num) {

	int i = 2;
	
	while (true) {
		int current = num * i++;
		if (current >= MAX_SIZE) break;

		if (visited[current]) {
			SCORE[num]++;
			SCORE[current]--;
		}
	}
}

int main() {
	FASTIO;
	cin >> N;
	vector<int> originNum(N);
	vector<int> num(N);

	for (int i = 0; i < N; i++) {
		cin >> num[i];
		visited[num[i]] = true;
		originNum[i] = num[i];
	}

	sort(num.begin(), num.end());

	for (int i = 0; i < N; i++) {
		calc(num[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << SCORE[originNum[i]] << ' ';
	}

	cout << endl;
}