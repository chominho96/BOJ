#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 100010

using namespace std;

long long N, Q;
long long NUMBER[MAX_SIZE];
long long SEG[MAX_SIZE * 4];

long long make(long long l, long long r, long long idx) {
    if (l == r) return SEG[idx] = NUMBER[l];
    long long mid = (l + r) / 2;
    return SEG[idx] = make(l, mid, idx * 2) + make(mid + 1, r, idx * 2 + 1);
}

void update(long long l, long long r, long long idx, long long tar, long long diff) {
    if (r < tar || l > tar) return;
    SEG[idx] += diff;
    if (l == r) return;
    long long mid = (l + r) / 2;
    update(l, mid, idx * 2, tar, diff);
    update(mid + 1, r, idx * 2 + 1, tar, diff);
}

long long sum(long long l, long long r, long long idx, long long from, long long to) {
    if (l > to || r < from) return 0;
    if (from <= l && r <= to) return SEG[idx];
    long long mid = (l + r) / 2;
    return sum(l, mid, idx * 2, from, to) + sum(mid + 1, r, idx * 2 + 1, from, to);
}

int main() {
    FASTIO
    cin >> N >> Q; for (int i = 1; i <= N; i++) cin >> NUMBER[i];
    make(1, N, 1);
    while (Q--) {
        long long x, y, a, b; cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);\
        cout << sum(1, N, 1, x, y) << '\n';
        update(1, N, 1, a, b - NUMBER[a]);
        NUMBER[a] = b;
    }
}