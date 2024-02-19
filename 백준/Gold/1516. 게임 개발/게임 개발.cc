#include <iostream>
#include <vector>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 510

using namespace std;

int N;
vector<int> MAP[MAX_SIZE];
int INCOME[MAX_SIZE];
int TIME[MAX_SIZE];
int RESULT[MAX_SIZE];
queue<int> que;

void init() {
    for (int i = 1; i <= N; i++) {
        if (INCOME[i] == 0) {
            RESULT[i] = TIME[i];
            que.push(i);
        }
    }
}

void calc() {
    while (!que.empty()) {
        int curr = que.front();
        que.pop();
        for (int i = 0; i < MAP[curr].size(); i++) {
            int next = MAP[curr][i];
            RESULT[next] = max(RESULT[next], RESULT[curr] + TIME[next]);
            if (--INCOME[next] == 0) que.push(next);
        }
    }
}

void print() {
    for (int i = 1; i <= N; i++) {
        cout << RESULT[i] << endl;
    }
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> TIME[i];
        while (true) {
            int in; cin >> in;
            if (in == -1) break;
            MAP[in].push_back(i);
            INCOME[i]++;
        }
    }
    init();
    calc();
    print();
}