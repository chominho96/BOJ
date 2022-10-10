#include <iostream>
#include <string>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

string saw[4];

void turn(int index, bool clockDir) {
	if (clockDir) {
		// 맨 뒤가 앞으로오는 상황
		saw[index] = saw[index][saw[index].size() - 1] + saw[index];
		saw[index].pop_back();
	}
	else {
		// 맨 앞이 뒤로 가는 상황
		saw[index] = saw[index] + saw[index][0];
		saw[index] = saw[index].substr(1);
	}
}


// 회전할지 여부는 2번 index, 6번 index에 의해 결정
void calculate(int index, int dir) {
	bool* isTurn = new bool[3];
	if (saw[0][2] != saw[1][6]) {
		isTurn[0] = true;
	}
	else {
		isTurn[0] = false;
	}
	if (saw[1][2] != saw[2][6]) {
		isTurn[1] = true;
	}
	else {
		isTurn[1] = false;
	}
	if (saw[2][2] != saw[3][6]) {
		isTurn[2] = true;
	}
	else {
		isTurn[2] = false;
	}

	int idx = index - 1;
	bool isClockDir = false;
	if (dir == 1) {
		isClockDir = true;
	}
	// go left
	while (true) {
		if (idx < 0) {
			break;
		}

		if (isTurn[idx]) {
			turn(idx, !isClockDir);
			isClockDir = !isClockDir;
		}
		else {
			break;
		}

		idx--;

	}

	if (dir == 1) {
		isClockDir = true;
	}
	else {
		isClockDir = false;
	}

	turn(index, isClockDir);

	idx = index;
	// go right
	while (true) {
		if (idx >= 3) {
			break;
		}

		if (isTurn[idx]) {
			turn(idx + 1, !isClockDir);
			isClockDir = !isClockDir;
		}
		else {
			break;
		}
		idx++;
	}

	delete[] isTurn;
}

int main() {
	FASTIO;
	
	cin >> saw[0] >> saw[1] >> saw[2] >> saw[3];
	int K;
	cin >> K;

	for (int _ = 0; _ < K; _++) {
		int idx, dir;
		cin >> idx >> dir;
		calculate(idx - 1, dir);
	}

	int ans = 0;
	if (saw[0][0] == '1') {
		ans += 1;
	}
	if (saw[1][0] == '1') {
		ans += 2;
	}
	if (saw[2][0] == '1') {
		ans += 4;
	}
	if (saw[3][0] == '1') {
		ans += 8;
	}

	cout << ans << '\n';
	
}