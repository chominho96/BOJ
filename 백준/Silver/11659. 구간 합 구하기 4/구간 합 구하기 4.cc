#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 100010

using namespace std;

int N, M;
long long NUMBER[MAX_SIZE];
long long SUM[MAX_SIZE];

void init() {
    for (int i = 1; i <= N; i++) {
        SUM[i] = SUM[i - 1] + NUMBER[i];
    }
}

long long sum(int from, int to) {
    return SUM[to] - SUM[from - 1];
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> NUMBER[i];
    }
    init();
    for (int _ = 0; _ < M; _++) {
        int i, j; cin >> i >> j;
        cout << sum(i, j) << endl;
    }
}