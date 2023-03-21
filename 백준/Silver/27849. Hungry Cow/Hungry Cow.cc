#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

using namespace std;

long long N, T;

int main() {
	FASTIO;
	cin >> N >> T;

	long long d, b;
	long long result = 0;
	long long rest = 0;
	long long day = 0;
	for (int i = 0; i < N; i++) {
		cin >> d >> b;

		if (rest > d - day) {
			result += (d - day);
			rest -= (d - day);
		}
		else {
			result += rest;
			rest = 0;
		}
		
		day = d;
		rest += b;
		
	}

	if (rest >= T - day + 1) {
		result += (T - day + 1);
	}
	else {
		result += rest;
	}

	cout << result << endl;
}