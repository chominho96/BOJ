#include <iostream>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	// case 1
	if (A == B && B == C) {
		cout << 10000 + A * 1000 << endl;
	}
	else if (A == B || A == C) {
		cout << 1000 + 100 * A << endl;;
	}
	else if (B == C) {
		cout << 1000 + 100 * B << endl;
	}
	else {
		cout << max(A, max(B, C)) * 100 << endl;
	}
}