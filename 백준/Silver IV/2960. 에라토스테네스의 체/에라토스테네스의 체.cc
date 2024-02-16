#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 1010

using namespace std;

int N, K;
bool IS_PRIME[MAX_SIZE];
bool visited[MAX_SIZE];

void judge(int& cnt, int tar) {
    if (visited[tar]) return;
    visited[tar] = true;
    if (++cnt == K) {
        cout << tar << endl;
        exit(0);
    }
}

void calc() {
    for (int i = 2; i <= N; i++) IS_PRIME[i] = true;
    int cnt = 0;
    int last = 0;
    for (int i = 2; i * i <= N; i++) {
        if (!IS_PRIME[i]) continue;
        judge(cnt, i);
        last = i;
        for (int j = i * i; j <= N; j += i) {
            judge(cnt, j);
            IS_PRIME[j] = false;
        }
    }
    for (int i = last + 1; i <= N; i++) {
        if (IS_PRIME[i]) judge(cnt, i);
    }
}

int main() {
    FASTIO
    cin >> N >> K;
    calc();
}