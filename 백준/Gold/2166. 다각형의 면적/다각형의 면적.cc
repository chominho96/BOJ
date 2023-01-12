#include <iostream>
#include <cmath>
#include <iomanip>
#define MAX_SIZE 10001
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'

using namespace std;

int N;
long double COORD[MAX_SIZE][2];

double calculate() {
	double ans = 0;
	for (int i = 2; i <= N - 1; i++) {
		double x1 = COORD[i][0] - COORD[1][0];
		double x2 = COORD[i + 1][0] - COORD[1][0];
		double y1 = COORD[i][1] - COORD[1][1];
		double y2 = COORD[i + 1][1] - COORD[1][1];

		ans += double((x1 * y2 - x2 * y1) / 2.0);
	}

	return abs(ans);
}

int main() {
	FASTIO;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> COORD[i][0] >> COORD[i][1];
	}
	
	cout << fixed;
	cout.precision(1);
	cout << calculate() << endl;
}