#include <iostream>
#include <vector>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 7

using namespace std;

char MAP[MAX_SIZE][MAX_SIZE];
int N;
vector<pair<int, int>> blank;
vector<pair<int, int>> teacher;

bool judge() {
	for (int i = 0; i < teacher.size(); i++) {
		for (int j = teacher[i].first - 1; j >= 1; j--) {
			if (MAP[j][teacher[i].second] == 'S') return false;
			else if (MAP[j][teacher[i].second] == 'O') break;
		}
		for (int j = teacher[i].first + 1; j <= N; j++) {
			if (MAP[j][teacher[i].second] == 'S') return false;
			else if (MAP[j][teacher[i].second] == 'O') break;
		}
		for (int j = teacher[i].second + 1; j <= N; j++) {
			if (MAP[teacher[i].first][j] == 'S') return false;
			else if (MAP[teacher[i].first][j] == 'O') break;
		}
		for (int j = teacher[i].second - 1; j >= 1; j--) {
			if (MAP[teacher[i].first][j] == 'S') return false;
			else if (MAP[teacher[i].first][j] == 'O') break;
		}
	}
	return true;
}

int main() {
	FASTIO;
	cin >> N;

	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] == 'X') {
				blank.push_back({ i, j });
			}
			else if (MAP[i][j] == 'T') {
				teacher.push_back({ i, j });
			}
		}
	}
	
	for (int i = 0; i < blank.size(); i++) {
		MAP[blank[i].first][blank[i].second] = 'O';
		for (int j = i + 1; j < blank.size(); j++) {
			MAP[blank[j].first][blank[j].second] = 'O';
			for (int k = j + 1; k < blank.size(); k++) {
				MAP[blank[k].first][blank[k].second] = 'O';
				if (judge()) {
					cout << "YES" << endl;
					return 0;
				}
				MAP[blank[k].first][blank[k].second] = 'X';
			}
			MAP[blank[j].first][blank[j].second] = 'X';
		}
		MAP[blank[i].first][blank[i].second] = 'X';
	}

	cout << "NO" << endl;

}