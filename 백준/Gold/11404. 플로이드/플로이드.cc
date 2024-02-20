#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 110
#define INF 987654321

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];
int n, m;

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (i != j) MAP[i][j] = INF;
        }
    }
}

void floyd() {
    for (int i = 1; i <= n; i++) {
        // i를 거쳐 가는 경우
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (j == k) continue;
                MAP[j][k] = min(MAP[j][k], MAP[j][i] + MAP[i][k]);
            }
        }
    }
}

void print() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (MAP[i][j] == INF) cout << 0 << ' ';
            else cout << MAP[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    FASTIO
    init();
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        MAP[a][b] = min(MAP[a][b], c);
    }
    floyd();
    print();
}