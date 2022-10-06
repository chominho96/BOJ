#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 21

using namespace std;

int CALMAP[MAX_SIZE][MAX_SIZE];
int N;

int numCal(vector<bool>& vec, bool b) {
	int num = 0;
	
	int cnt = N / 2 - 1;
	int index = 1;
	while (true) {
		if (vec[index] == b) {
			break;
		}
		index++;
	}

	int innerCnt = 0;
	int innerIdx = index + 1;
	while (true) {
		if (innerCnt == cnt) {
			if (cnt == 0) {
				break;
			}
			innerCnt = 0;
			cnt--;

			index++;
			while (true) {
				if (vec[index] == b) {
					break;
				}
				index++;
			}
			innerIdx = index + 1;
			continue;
		}

		if (vec[innerIdx] == b) {
			num += CALMAP[index][innerIdx];
			innerCnt++;
		}
		innerIdx++;
	}

	return num;
}

int ans = 987654321;
void calculate(vector<bool>& vec, int index, int count) {
	if (count == N / 2) {
		int num1 = numCal(vec, true);
		int num2 = numCal(vec, false);
		if (abs(num1 - num2) < ans) {
			ans = abs(num1 - num2);
		}
		return;
	}

	for (int i = index + 1; i <= N; i++) {
		vec[i] = true;
		calculate(vec, i, count + 1);
		vec[i] = false;
	}
}

int main() {
	cin >> N;

	int num;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			if (i > j) {
				CALMAP[j][i] += num;
			}
			else {
				CALMAP[i][j] += num;
			}
		}
	}

	vector<bool> vec(N + 1);
	for (int i = 1; i <= N; i++) {
		/*if (i == 2) {
			cout << "시작" << endl;
		}*/
		vec[i] = true;
		calculate(vec, i, 1);
		vec[i] = false;
	}
	
	
	
	cout << ans << '\n';
}