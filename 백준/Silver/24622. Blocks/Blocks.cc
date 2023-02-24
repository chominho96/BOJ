#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 5

using namespace std;

string BLOCK[MAX_SIZE];
string input;
bool block_visited[MAX_SIZE];
bool input_visited[MAX_SIZE];
bool success = false;
int N;

bool canContain(int block_index, int input_index) {
	for (int i = 0; i < BLOCK[block_index].size(); i++) {
		if (BLOCK[block_index][i] == input[input_index]) return true;
	}
	return false;
}

void calculate(int block_index, int input_index, int count) {

	if (success || !canContain(block_index, input_index)) return;

	if (count == input.size()) {
		success = true;
		cout << "YES" << endl;
		return;
	}
	
	for (int i = 0; i < input.size(); i++) {
		if (!input_visited[i]) {
			input_visited[i] = true;
			for (int j = 1; j < MAX_SIZE; j++) {
				if (!block_visited[j]) {
					block_visited[j] = true;
					calculate(j, i, count + 1);
					block_visited[j] = false;
				}
			}
			input_visited[i] = false;
		}
	}
}

void init() {
	success = false;
	for (int i = 0; i < MAX_SIZE; i++) {
		block_visited[i] = false;
		input_visited[i] = false;
	}
}

int main() {
	FASTIO;
	cin >> N;

	for (int i = 1; i < MAX_SIZE; i++) {
		cin >> BLOCK[i];
	}

	while (N--) {
		init();
		cin >> input;

		for (int i = 1; i < MAX_SIZE; i++) {
			block_visited[i] = true;
			input_visited[0] = true;
			calculate(i, 0, 1);
			block_visited[i] = false;
		}
		if (!success) {
			cout << "NO" << endl;
		}
	}

}