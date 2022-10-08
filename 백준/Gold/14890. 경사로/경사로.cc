#include <iostream>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 101

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE][2];
int N, L;

bool makeCanGo(int pin, int index, bool isUp) {
	if (index + L - 1 > N) {
		return false;
	}

	if (isUp) {
		for (int i = index + 1; i <= index + L; i++) {
			if (visited[pin][i][0] || MAP[pin][i] != MAP[pin][index + 1]) {
				return false;
			}
			visited[pin][i][0] = true;
		}
		return true;
	}
	else {
		for (int i = index + 1; i <= index + L; i++) {
			if (visited[i][pin][1] || MAP[i][pin] != MAP[index + 1][pin]) {
				return false;
			}
			visited[i][pin][1] = true;
		}
		return true;
	}
	
}
bool makeCanBack(int pin, int index, bool isUp) {
	if (index - L + 1 < 1) {
		return false;
	}

	if (isUp) {
		for (int i = index - 1; i >= index - L; i--) {
			if (visited[pin][i][0] || MAP[pin][i] != MAP[pin][index - 1]) {
				return false;
			}
			visited[pin][i][0] = true;
		}
		return true;
	}
	else {
		for (int i = index - 1; i >= index - L; i--) {
			if (visited[i][pin][1] || MAP[i][pin] != MAP[index - 1][pin]) {
				return false;
			}
			visited[i][pin][1] = true;
		}
		return true;
	}
}

bool calculate(int index, bool isUp) {
	bool success = true;
	
	if (isUp) {

		for (int i = 1; i < N; i++) {
			if (MAP[index][i] == MAP[index][i + 1]) {
				// success
			}
			else if (visited[index][i][0] && MAP[index][i] + 1 == MAP[index][i + 1]) {
				success = false;
				break;
			}
			else if (MAP[index][i] + 1 == MAP[index][i + 1]) {
				if (!makeCanBack(index, i + 1, true)) {
					success = false;
					break;
				}
			}
			else if (MAP[index][i] - 1 == MAP[index][i + 1]) {
				if (!makeCanGo(index, i, true)) {
					success = false;
					break;
				}
			}
			else {
				success = false;
				break;
			}
		}
	}
	else {
		for (int i = 1; i < N; i++) {
			if (MAP[i][index] == MAP[i + 1][index]) {
				// success
			}
			else if (visited[i][index][1] && MAP[i][index] + 1 == MAP[i + 1][index]) {
				success = false;
				break;
			}
			else if (MAP[i][index] + 1 == MAP[i + 1][index]) {
				if (!makeCanBack(index, i + 1, false)) {
					success = false;
					break;
				}
			}
			else if (MAP[i][index] - 1 == MAP[i + 1][index]) {
				if (!makeCanGo(index, i, false)) {
					success = false;
					break;
				}
			}
			else {
				success = false;
				break;
			}
		}
	}

	return success;

	
}


int main() {
	FASTIO;
	cin >> N >> L;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		
		if (calculate(i, true)) {
			ans++;
		}

		if (calculate(i, false)) {
			ans++;
		}
	}

	cout << ans << '\n';
	
}