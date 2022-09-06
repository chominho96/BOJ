#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;

	getline(cin, str);

	int ans = 0;
	bool isStart = false;
	for (int i = 0; i < str.size(); i++) {
		if (!isStart && ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
			// start word
			ans++;
			isStart = true;
		}
		else if (isStart && str[i] == ' ') {
			// end word
			isStart = false;
			
		}
	}
	cout << ans << '\n';

}