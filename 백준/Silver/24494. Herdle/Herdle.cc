#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 4
#define ALPHA_SIZE 26
#define endl '\n'

using namespace std;

char ANSWER[MAX_SIZE][MAX_SIZE];
char GUESS[MAX_SIZE][MAX_SIZE];
int visited[ALPHA_SIZE];

int main() {
	FASTIO;

	string input;
	for (int i = 1; i <= 3; i++) {
		cin >> input;
		for (int j = 1; j <= 3; j++) {
			ANSWER[i][j] = input[j - 1];
			visited[ANSWER[i][j] - 'A']++;
		}
	}
	for (int i = 1; i <= 3; i++) {
		cin >> input;
		for (int j = 1; j <= 3; j++) {
			GUESS[i][j] = input[j - 1];
		}
	}

	int green = 0;
	int yellow = 0;

	// 1. correct
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (ANSWER[i][j] == GUESS[i][j]) {
				green++;
				visited[GUESS[i][j] - 'A']--;
			}
		}
	}

	// 2. wrong
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (GUESS[i][j] != ANSWER[i][j] && visited[GUESS[i][j] - 'A'] > 0) {
				yellow++;
				visited[GUESS[i][j] - 'A']--;
			}
		}
	}

	cout << green << endl << yellow << endl;

}