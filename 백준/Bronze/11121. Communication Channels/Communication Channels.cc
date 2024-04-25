#include <iostream>

using namespace std;

int main() {

	int T; cin >> T;
	while (T--) {
		string s1, s2; cin >> s1 >> s2;
		if (s1 == s2) cout << "OK\n";
		else cout << "ERROR\n";
	}
}