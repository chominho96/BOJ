#include <iostream>
#include <vector>
#include <map>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl '\n'
#define MAX_SIZE 1001

using namespace std;

long long T;
int n, m;
long long A[MAX_SIZE];
long long B[MAX_SIZE];

vector<long long> A_SUM;
map<long long, int> mp;

long long ans = 0;
void calculate_a(int index, long long current) {
	if (index > n) return;
	long long next = current + A[index];
	A_SUM.push_back(next);
	calculate_a(index + 1, next);
}

void calculate_b(int index, long long current) {
	if (index > m) return;
	long long next = current + B[index];
	if (mp.find(next) != mp.end()) {
		mp[next] += 1;
	}
	else mp.insert({ next, 1 });
	calculate_b(index + 1, next);
}

int main() {
	FASTIO;
	cin >> T >> n;
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
	}
	for (int i = 1; i <= n; i++) {
		calculate_a(i, 0);
	}
	for (int i = 1; i <= m; i++) {
		calculate_b(i, 0);
	}

	for (int i = 0; i < A_SUM.size(); i++) {
		long long target = T - A_SUM[i];
		if (mp.find(target) != mp.end()) {
			ans += mp[target];
		}
	}
	cout << ans << endl;
}