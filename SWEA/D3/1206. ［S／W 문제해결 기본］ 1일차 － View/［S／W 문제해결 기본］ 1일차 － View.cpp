#include <iostream>
#define MAX_SIZE 1010

using namespace std;

int BUILDING[MAX_SIZE];
int N;
int T = 10;

int calc(const int& idx) {
    int left1 = idx <= 1 ? 0 : BUILDING[idx - 1];
    int left2 = idx <= 2 ? 0 : BUILDING[idx - 2];
    int left = max(left1, left2);

    int right1 = idx >= N ? 0 : BUILDING[idx + 1];
    int right2 = idx >= N - 1 ? 0 : BUILDING[idx + 2];
    int right = max(right1, right2);

    int maxFloor = max(left, right);

    return BUILDING[idx] - maxFloor >= 0 ? BUILDING[idx] - maxFloor : 0;
}

int main() {
    //freopen("input.txt", "r", stdin);

    for (int i = 1; i <= T; i++) {
        cin >> N;
        for (int j = 1; j <= N; j++) {
            cin >> BUILDING[j];
        }

        int ans = 0;
        for (int j = 1; j <= N; j++) {
            ans += calc(j);
        }

        cout << "#" << i << ' ' << ans << '\n';
    }

    return 0;
}