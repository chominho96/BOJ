#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;
int N, K, maxDigit;

void calculate(int idx, int current, int digit) {

	// end condition
	if (digit == maxDigit) {
		if (current <= N) {
			cout << current << '\n';
			exit(0);
		}
		return;
	}

	for (int i = vec.size() - 1; i >= 0; i--) {
		calculate(i, current * 10 + vec[i], digit + 1);
	}
	
}

int main() {
	int input;
	cin >> N >> K;

	// calculate maxDigit
	maxDigit = 1;
	int temp = 1;
	while (true) {
		if (N >= temp) {
			maxDigit++;
			temp *= 10;
		}
		else {
			maxDigit--;
			break;
		}
	}


	vec.resize(K);

	for (int i = 0; i < K; i++) {
		cin >> input;
		vec[i] = input;
	}

	sort(vec.begin(), vec.end());

	while (true) {
		for (int i = vec.size() - 1; i >= 0; i--) {
			calculate(i, vec[i], 1);
		}
		
		maxDigit--;
	}

}