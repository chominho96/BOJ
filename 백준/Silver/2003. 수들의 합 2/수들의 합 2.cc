#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 10001

using namespace std;

int N, M;
int NUMBER[MAX_SIZE];
int ans = 0;

void calc(int idx, int value) {
    if (value == M) {
        ans++;
        return;
    }
    if (value > M || idx > N) return;
    calc(idx + 1, value + NUMBER[idx + 1]);
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> NUMBER[i];
    }
    for (int i = 1; i <= N; i++) {
        calc(i, NUMBER[i]);
    }
    cout << ans << '\n';
}