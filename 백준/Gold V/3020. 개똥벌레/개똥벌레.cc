#include <iostream>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 500010

using namespace std;

int N, H;
long long DOWN[MAX_SIZE];
long long UP[MAX_SIZE];

void sum() {
    for (int i = 1; i <= H; i++) {
        DOWN[i] = DOWN[i - 1] + DOWN[i];
        UP[i] = UP[i - 1] + UP[i];
    }
}

long long getDamage(long long* arr, int h) {
    return arr[H] - arr[h - 1];
}

void calc() {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 1; i <= H; i++) {
        pq.push(getDamage(UP, i) + getDamage(DOWN, H - i + 1));
    }
    int min = pq.top();
    int cnt = 0;
    while (!pq.empty()) {
        if (pq.top() == min) cnt++;
        else break;
        pq.pop();
    }
    cout << min << ' ' << cnt << '\n';
}

int main() {
    FASTIO
    cin >> N >> H;
    for (int i = 0; i < N; i++) {
        int n; cin >> n;
        if (i % 2 == 0) DOWN[n]++;
        else UP[n]++;
    }
    sum(); calc();
}