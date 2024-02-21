#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 210
#define INF 1000000010

using namespace std;

long long N, M, K;
long long DP[MAX_SIZE][MAX_SIZE];
string ans;

long long calc(long long n, long long m) {
    if (DP[n][m] != 0) return DP[n][m];
    if (m == 0 || m == n) return DP[n][m] = 1;
    long long value = calc(n - 1, m) + calc(n - 1, m - 1);
    return DP[n][m] = value > INF ? INF : value;
}

void init() {
    for (long long i = 1; i < MAX_SIZE; i++) {
        for (long long j = i; j >= 0; j--) {
            calc(i, j);
        }
    }
}

// a가 n개, b가 m개일 때 k번째를 고르기
void find(long long n, long long m, long long k) {
    while (true) {
        if (n < 0 || m < 0) {
            cout << -1 << endl;
            exit(0);
        }
        if (k == 1) {
            for (long long i = 0; i < n; i++) {
                ans += 'a';
            }
            for (long long i = 0; i < m; i++) {
                ans += 'z';
            }
            break;
        }
        if (k <= DP[n - 1 + m][m]) {
            ans += 'a';
            n--;
        }
        else {
            ans += 'z';
            k -= DP[n - 1 + m][m];
            m--;
        }
    }
    cout << ans << endl;
}

int main() {
    FASTIO
    init();
    cin >> N >> M >> K;
    find(N, M, K);
}