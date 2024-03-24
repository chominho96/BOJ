#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 200010

using namespace std;

struct node {
    int n1 = -1; 
    int n2 = -1; 
    int len = -1;
};

node DP[MAX_SIZE][3];
int FRUIT[MAX_SIZE];
int N;
int m = 1;

void dp() {
    DP[1][1] = {FRUIT[1], -1, 1};
    int prev_idx = 1;
    int prev = FRUIT[prev_idx];

    for (int i = 2; i <= N; i++) {
        if (FRUIT[i] == FRUIT[i - 1]) {
            DP[i][1] = {FRUIT[i], -1, DP[i - 1][1].len + 1};
            m = max(m, DP[i][1].len);
            if (DP[i - 1][2].len != -1) {
                DP[i][2] = DP[i - 1][2];
                m = max(m, ++DP[i][2].len);
            }
        }
        else {
            DP[i][1] = {FRUIT[i], -1, 1};
            if (DP[i - 1][2].n1 == FRUIT[i] || DP[i - 1][2].n2 == FRUIT[i]) {
                DP[i][2] = DP[i - 1][2];
                m = max(m, ++DP[i][2].len);
            }
            else {
                DP[i][2] = {prev, FRUIT[i], i - prev_idx + 1};
                m = max(m, DP[i - 2][2].len);
            }
            prev_idx = i;
            prev = FRUIT[prev_idx];
        }
    }
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> FRUIT[i];
    }
    dp();
    cout << m << endl;
}