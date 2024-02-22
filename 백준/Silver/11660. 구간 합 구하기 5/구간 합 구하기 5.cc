#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 1050

using namespace std;

int N, M;
int NUMBER[MAX_SIZE][MAX_SIZE];
int SUM[MAX_SIZE][MAX_SIZE];

void init() {
    for (int i = 1; i < MAX_SIZE; i++) {
        for (int j = 1; j < MAX_SIZE; j++) {
            SUM[i][j] = SUM[i][j - 1] + NUMBER[i][j];
        }
    }
}

int sum(int x1, int y1, int x2, int y2) {
    int result = 0;
    for (int i = x1; i <= x2; i++) {
        result += SUM[i][y2] - SUM[i][y1 - 1];
    }
    return result;
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> NUMBER[i][j];
        }
    }
    init();
    while (M--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << sum(x1, y1, x2, y2) << endl;
    }
}