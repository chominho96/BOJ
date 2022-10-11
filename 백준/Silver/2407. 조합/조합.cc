#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// nCm = n-1Cr + n-1Cr-1

int n, m;

string DP[101][101];
bool visited[101][101];

string add(string s1, string s2) {
	if (s1.size() < s2.size()) {
		// s1이 항상 크게 정렬
		swap(s1, s2);
	}

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	for (int i = 0; i < s2.size(); i++) {
		int current = s2[i] - '0';

		for (int j = i; j < s1.size(); j++) {
			int currentS1 = s1[j] - '0';
			if (current + currentS1 >= 10) {
				s1[j] = '0' + (current + currentS1 - 10);
				if (j == s1.size() - 1) {
					s1.push_back('1');
					break;
				}
				else {
					current = 1;
				}
			}
			else {
				s1[j] = '0' + (current + currentS1);
				break;
			}
		}
	}

	reverse(s1.begin(), s1.end());
	return s1;

}

string combination(int n, int m) {
	
	if (visited[n][m]) {
		return DP[n][m];
	}

	if (n == m || n == 1) {
		return "1";
	}

	if (m == 1) {
		return to_string(n);
	}

	DP[n][m] = add(combination(n - 1, m), combination(n - 1, m - 1));
	visited[n][m] = true;

	//cout << n << "C" << m <<" == " << DP[n][m] << '\n';

	return DP[n][m];
}

int main() {
	cin >> n >> m;

	cout << combination(n, m) << '\n';
}