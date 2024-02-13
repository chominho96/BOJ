#include <iostream>
#include <utility>
#include <map>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 1000010

using namespace std;

long long NUMBER[MAX_SIZE];
pair<long long, long long> EDGE[MAX_SIZE];
long long N, M, K;
long long SUM = 0;
map<long long, long long> mp;

long long getSum(long long i, long long j) {
    long long ans = SUM - EDGE[i].first - EDGE[j].second;
    for (auto it = mp.upper_bound(i - 1); it != mp.end(); it++) {
        if (it->first > j) break;
        ans = ans - NUMBER[it->first] + it->second;
    }
    return ans;
}

int main() {
    FASTIO
    cin >> N >> M >> K;
    for (long long i = 1; i <= N; i++) {
        cin >> NUMBER[i];
        EDGE[i].first = SUM;
        SUM += NUMBER[i];
    }
    long long right = 0;
    for (long long i = N; i >= 1; i--) {
        EDGE[i].second = right;
        right += NUMBER[i];
    }

    for (long long i = 0; i < M + K; i++) {
        long long a, b, c; cin >> a >> b >> c;
        if (a == 1) {
            // b번째 수를 c로 바꾸기
            mp[b] = c;
        } else {
            // b부터 c까지의 합 구하기
            cout << getSum(b, c) << '\n';
        }
    }
}