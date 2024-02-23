#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define NODE_SIZE 17
#define ROUTE_SIZE 150000
#define INF 987654321

using namespace std;

int DP[NODE_SIZE][ROUTE_SIZE];
int MAP[NODE_SIZE][NODE_SIZE];
int N;

void init() {
    for (int i = 0; i < NODE_SIZE; i++) {
        for (int j = 0; j < ROUTE_SIZE; j++) {
            DP[i][j] = -1;
        }
    }
}

int dfs(int curr, int visited) {
    if (visited == (1 << N) - 1) {
        if (MAP[curr][0] == 0) return INF;
        return MAP[curr][0];
    }
    
    if (DP[curr][visited] != -1) return DP[curr][visited];
    DP[curr][visited] = INF;

    for (int i = 1; i < N; i++) {
        if (MAP[curr][i] == 0) continue;
        if ((visited & (1 << i)) == (1 << i)) continue;
        DP[curr][visited] = min(DP[curr][visited], MAP[curr][i] + dfs(i, visited | 1 << i));
    }

    return DP[curr][visited];
}

int main() {
    FASTIO
    init();
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }
    cout << dfs(0, 1) << endl;
}