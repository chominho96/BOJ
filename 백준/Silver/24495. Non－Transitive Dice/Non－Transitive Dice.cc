#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 5
#define DICE_NUM 4

using namespace std;

int DICE[DICE_NUM][MAX_SIZE];
bool Awin = false;

int fight(int left, int right) {
	int left_num = 0;
	int right_num = 0;

	for (int i = 1; i < MAX_SIZE; i++) {
		for (int j = 1; j < MAX_SIZE; j++) {
			if (DICE[left][i] > DICE[right][j]) left_num++;
		}
	}
	for (int i = 1; i < MAX_SIZE; i++) {
		for (int j = 1; j < MAX_SIZE; j++) {
			if (DICE[right][i] > DICE[left][j]) right_num++;
		}
	}

	if (left_num > right_num) return left;
	if (right_num > left_num) return right;
	return -1;
}

void calculate() {
	for (int i = 1; i <= 10; i++) {
		DICE[3][1] = i;
		for (int j = 1; j <= 10; j++) {
			DICE[3][2] = j;
			for (int k = 1; k <= 10; k++) {
				DICE[3][3] = k;
				for (int n = 1; n <= 10; n++) {
					DICE[3][4] = n;

					if (Awin) {
						if (fight(3, 1) == 3 && fight(2, 3) == 2) {
							cout << "yes" << endl;
							return;
						}
					}
					else {
						if (fight(3, 2) == 3 && fight(1, 3) == 1) {
							cout << "yes" << endl;
							return;
						}
					}
				}
			}
		}
	}

	cout << "no" << endl;
}

int main() {
	FASTIO;
	int T; cin >> T;
	while (T--) {
		Awin = false;

		for (int i = 1; i <= 4; i++) {
			cin >> DICE[1][i];
		}
		for (int i = 1; i <= 4; i++) {
			cin >> DICE[2][i];
		}

		// 1. A가 B를 이기는지, B가 A를 이기는지 판단
		int AfightB = fight(1, 2);
		if (AfightB == -1) {
			cout << "no" << endl;
			continue;
		}
		
		if (AfightB == 1) {
			Awin = true;
		}

		// 2. C를 바꿔가면서 각 상황에 맞는 판단
		calculate();

	}
}