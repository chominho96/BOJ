#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 24

using namespace std;

char MAP[MAX_SIZE][MAX_SIZE];
char PAPER[MAX_SIZE][MAX_SIZE];
char STAMP[MAX_SIZE][MAX_SIZE][4];

int N, K;

void init() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			PAPER[i][j] = '.';
		}
	}
}

void makeStamp() {

	for (int i = K; i >= 1; i--) {
		for (int j = 1; j <= K; j++) {
			STAMP[j][i][1] = STAMP[K - i + 1][j][0];
		}
	}

	for (int i = K; i >= 1; i--) {
		for (int j = 1; j <= K; j++) {
			STAMP[j][i][2] = STAMP[K - i + 1][j][1];
		}
	}

	for (int i = K; i >= 1; i--) {
		for (int j = 1; j <= K; j++) {
			STAMP[j][i][3] = STAMP[K - i + 1][j][2];
		}
	}
}

bool success() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (PAPER[i][j] != MAP[i][j]) return false;
		}
	}

	return true;
}

bool stamping(int row, int col) {
	if (row + K > N + 1 || col + K > N + 1) {
		return false;
	}

	bool CAN_STAMP[] = { true, true, true, true };

	for (int i = 0; i < 4; i++) {
		for (int j = row; j < row + K; j++) {
			for (int k = col; k < col + K; k++) {
				if (MAP[j][k] == '.' && STAMP[j - row + 1][k - col + 1][i] == '*') {
					CAN_STAMP[i] = false;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (CAN_STAMP[i]) {
			for (int j = row; j < row + K; j++) {
				for (int k = col; k < col + K; k++) {
					if (STAMP[j - row + 1][k - col + 1][i] == '*') {
						PAPER[j][k] = '*';
					}
				}
			}
		}
	}

	return success();
	
}

void mainJob() {

	for (int i = 1; i <= N - K + 1; i++) {
		for (int j = 1; j <= N - K + 1; j++) {
			if (stamping(i, j)) {
				cout << "YES" << endl;
				return;
			}
		}
	}

	if (success()) {
		cout << "YES" << endl;
		return;
	}

	cout << "NO" << endl;
}

int main() {
	FASTIO;
	int T; cin >> T;
	while (T--) {

		init();
		cin >> N;
		string str;
		for (int i = 1; i <= N; i++) {
			cin >> str;
			for (int j = 1; j <= N; j++) {
				MAP[i][j] = str[j - 1];
			}
		}

		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> str;
			for (int j = 1; j <= K; j++) {
				STAMP[i][j][0] = str[j - 1];
			}
		}

		makeStamp();
		mainJob();
	}
}