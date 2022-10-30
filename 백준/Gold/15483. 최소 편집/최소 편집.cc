#include <iostream>
#include <string>
#include <cmath>
#define MAX_SIZE 1001
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

string X, Y;

int EDIT_DISTANCE[MAX_SIZE][MAX_SIZE];

void initialize() {
	for (int i = 0; i < MAX_SIZE; i++) {
		EDIT_DISTANCE[0][i] = i;
		EDIT_DISTANCE[i][0] = i;
	}
}

void DP() {
	for (int i = 0; i < X.size(); i++) {
		for (int j = 0; j < Y.size(); j++) {
			if (X[i] == Y[j]) EDIT_DISTANCE[i + 1][j + 1] = EDIT_DISTANCE[i][j];
			else EDIT_DISTANCE[i + 1][j + 1] = min(EDIT_DISTANCE[i][j], min(EDIT_DISTANCE[i][j + 1], EDIT_DISTANCE[i + 1][j])) + 1;
		}
	}
}

int main() {
	FASTIO;
	initialize();
	cin >> X >> Y;
	DP();
	cout << EDIT_DISTANCE[X.size()][Y.size()] << '\n';
}