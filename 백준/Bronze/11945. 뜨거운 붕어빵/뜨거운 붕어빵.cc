#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 15

using namespace std;

int MAP[MAX_SIZE][MAX_SIZE];

int main() {
    FASTIO
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string str; cin >> str;
        for (int j = 1; j <= M; j++) {
            MAP[i][j] = str[j - 1] - '0';
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= 1; j--) {
            cout << MAP[i][j];
        }
        cout << endl;
    }
}