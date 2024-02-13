#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 10010

using namespace std;

int N, M;
int NUMBER[MAX_SIZE];
int SUM = 0;
int ans = 0;

void calc() {
    int left = 1;
    int right = N;
    while (true) {
        if (left > right) break;
        if (SUM == M) {
            ans++;
            break;
        }
        int sum = SUM;
        int l = left;
        int r = right;
        while (sum > M && l <= r) {
            sum -= NUMBER[r--];
        }
        if (sum == M) ans++;
        r = right;
        sum = SUM;
        while (sum > M && l <= r) {
            sum -= NUMBER[l++];
        }
        if (sum == M) ans++;
        SUM -= (NUMBER[left++] + NUMBER[right--]);
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> NUMBER[i];
        SUM += NUMBER[i];
    }
    calc();
    cout << ans << '\n';
}