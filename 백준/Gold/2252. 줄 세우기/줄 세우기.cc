#include <iostream>
#include <queue>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 32010

using namespace std;

int N, M;
vector<int> MAP[MAX_SIZE];
int INCOME[MAX_SIZE];
queue<int> que;

void init() {
    for (int i = 1; i <= N; i++) {
        if (INCOME[i] == 0) que.push(i);
    }
}

void calc() {
    while (!que.empty()) {
        int curr = que.front();
        que.pop();
        cout << curr << ' ';
        for (int i = 0; i < MAP[curr].size(); i++) {
            if (--INCOME[MAP[curr][i]] == 0) que.push(MAP[curr][i]);
        }
    }
    cout << endl;
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B; cin >> A >> B;
        MAP[A].push_back(B);
        INCOME[B]++;
    }
    init();
    calc();
}