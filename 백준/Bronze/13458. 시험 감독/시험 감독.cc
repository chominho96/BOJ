#include <iostream>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAX_SIZE 1000001

using namespace std;

int PERSON[MAX_SIZE];

int main() {
	FASTIO;

	int N, B, C;
	cin >> N;

	long long ans = 0;

	for (int i = 1; i <= N; i++) {
		cin >> PERSON[i];
	}
	cin >> B >> C;
	
	for (int i = 1; i <= N; i++) {
		ans++;
		PERSON[i] -= B;
		
		if (PERSON[i] > 0) {
			if (PERSON[i] % C == 0) {
				ans += (PERSON[i] / C);
			}
			else {
				ans += (PERSON[i] / C + 1);
			}
		}
	}

	cout << ans << '\n';
}