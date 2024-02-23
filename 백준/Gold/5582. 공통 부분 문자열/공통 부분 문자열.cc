#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 4010

using namespace std;

string s1, s2;
int DP[MAX_SIZE][MAX_SIZE];
int result = 0;

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            DP[i][j] = -1;
        }
    }
}

int lcs(int i, int j) {
    if (DP[i][j] != -1) return DP[i][j];
    if (i == 0 || j == 0 || s1[i] != s2[j]) return DP[i][j] = 0;
    DP[i][j] = lcs(i - 1, j - 1) + 1;
    result = max(result, DP[i][j]);
    return DP[i][j];
}

void calc() {
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            DP[i][j] = lcs(i, j);
        }
    }
}

int main() {
    FASTIO
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    init();
    calc();
    cout << result << endl;
}