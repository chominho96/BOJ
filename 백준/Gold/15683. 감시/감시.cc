#include <iostream>
#include <vector>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 9
#define endl '\n'

using namespace std;

struct cctv {
	int type; // 1, 2, 3, 4, 5
	int dir; // 1: right, 2: down, 3: left, 4: up
	int row;
	int col;
};

int N, M;
int MAP[MAX_SIZE][MAX_SIZE];	// -1은 감시되는 구역
vector<cctv> cctvList;
int ans = 987654321;

void init() {
	
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			if (MAP[i][j] == -1) MAP[i][j] = 0;
		}
	}
}

bool convertCell(const int& row, const int& col) {

	if (MAP[row][col] == 6) return false;
	if (MAP[row][col] == 0) MAP[row][col] = -1;
	return true;
}

void makeMap() {
	for (int i = 0; i < cctvList.size(); i++) {

		switch (cctvList[i].type) {

		case 1:
			switch (cctvList[i].dir) {
			case 1:
				for (int j = cctvList[i].row; j <= N; j++) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				break;
			case 2:
				for (int j = cctvList[i].row; j >= 1; j--) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				break;
			case 3:
				for (int j = cctvList[i].col; j <= M; j++) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			default:	// case 4
				for (int j = cctvList[i].col; j >= 1; j--) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			}
			break;
		case 2:
			switch (cctvList[i].dir) {
			case 1:
			case 3:
				for (int j = cctvList[i].row; j <= N; j++) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].row; j >= 1; j--) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				break;
			default:	// case 2, 4
				for (int j = cctvList[i].col; j <= M; j++) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				for (int j = cctvList[i].col; j >= 1; j--) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			}
			break;
		case 3:
			switch (cctvList[i].dir) {
			case 1:
				for (int j = cctvList[i].row; j <= N; j++) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].col; j <= M; j++) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			case 2:
				for (int j = cctvList[i].row; j <= N; j++) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].col; j >= 1; j--) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			case 3:
				for (int j = cctvList[i].row; j >= 1; j--) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].col; j <= M; j++) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			default:	// case 4
				for (int j = cctvList[i].row; j >= 1; j--) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].col; j >= 1; j--) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			}
			break;
		case 4:
			switch (cctvList[i].dir) {
			case 1:
				for (int j = cctvList[i].row; j <= N; j++) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].row; j >= 1; j--) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].col; j <= M; j++) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			case 2:
				for (int j = cctvList[i].row; j <= N; j++) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].row; j >= 1; j--) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].col; j >= 1; j--) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			case 3:
				for (int j = cctvList[i].row; j <= N; j++) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].col; j <= M; j++) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				for (int j = cctvList[i].col; j >= 1; j--) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			default:	// case 4
				for (int j = cctvList[i].row; j >= 1; j--) {
					if (!convertCell(j, cctvList[i].col)) break;
				}
				for (int j = cctvList[i].col; j <= M; j++) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				for (int j = cctvList[i].col; j >= 1; j--) {
					if (!convertCell(cctvList[i].row, j)) break;
				}
				break;
			}
			break;
		default:	// case 5
			for (int j = cctvList[i].row; j <= N; j++) {
				if (!convertCell(j, cctvList[i].col)) break;
			}
			for (int j = cctvList[i].row; j >= 1; j--) {
				if (!convertCell(j, cctvList[i].col)) break;
			}
			for (int j = cctvList[i].col; j <= M; j++) {
				if (!convertCell(cctvList[i].row, j)) break;
			}
			for (int j = cctvList[i].col; j >= 1; j--) {
				if (!convertCell(cctvList[i].row, j)) break;
			}
			break;
		}
	}
}

int calc() {
	
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (MAP[i][j] == 0) ans++;
		}
	}

	return ans;
}

void cctvTurn(int index, int dir) {

	cctvList[index].dir = dir;

	if (index == cctvList.size() - 1) {		// end condition

		makeMap();
		int currentAns = calc();
		if (currentAns < ans) {

			ans = currentAns;
		}

		init();
		return;
	}

	for (int i = 1; i <= 4; i++) {
		cctvTurn(index + 1, i);
	}
}


int main() {

	FASTIO;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> MAP[i][j];
			
			if (MAP[i][j] >= 1 && MAP[i][j] <= 5) {
				cctvList.push_back({ MAP[i][j], 1, i, j });
			}
		}
	}

	if (cctvList.size() == 0) {
		cout << calc() << endl;
		return 0;
	}

	for (int i = 1; i <= 4; i++) {
		cctvTurn(0, i);
	}

	cout << ans << endl;
	
}