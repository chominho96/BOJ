#include <iostream>
#include <algorithm>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 1000010

using namespace std;

long long N, M;
long long TREE[MAX_SIZE];
long long SUM[MAX_SIZE];

void init() {
    sort(TREE, TREE + N);
    SUM[0] = TREE[0];
    for (int i = 1; i < N; i++) {
        SUM[i] = SUM[i - 1] + TREE[i];
    }
}

// value보다 작거나 같은 최대 인덱스
long long search(long long l, long long r, long long value) {
    if (l >= r) return l;
    else if (r - l == 1) {
        if (TREE[r] <= value) return r;
        return l;
    }
    long long mid = (l + r) / 2;
    if (TREE[mid] > value) return search(l, mid - 1, value);
    else if (TREE[mid] == value) {
        for (long long i = mid; i < N; i++) {
            if (TREE[i] == TREE[mid]) continue;
            else return i - 1;
        }
        return N - 1;
    }
    else return search(mid, r, value);
}

bool possible(long long h) {
    long long idx = search(0, N - 1, h);
    if (TREE[idx] > h) {
        long long sum = SUM[N - 1] - (h * N);
        return sum >= M;
    }
    long long sum = SUM[N - 1] - SUM[idx] - (h * (N - idx - 1));
    return sum >= M;
}

long long search(long long l, long long r) {
    if (l >= r) return l;
    else if (r - l == 1) {
        if (possible(r)) return r;
        else return l;
    }
    long long mid = (l + r) / 2;
    if (possible(mid)) {
        return search(mid, r);
    } else {
        return search(l, mid - 1);
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> TREE[i];
    }
    init();
    cout << search(0, TREE[N - 1]) << '\n';
}