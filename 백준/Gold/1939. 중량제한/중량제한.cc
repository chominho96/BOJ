#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 10010
#define MAX_VALUE 1000000000

using namespace std;

struct edge {
    int to;
    int val;
};

int N, M;
vector<edge> MAP[MAX_SIZE];
bool visited[MAX_SIZE];
int fac1, fac2;

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        visited[i] = false;
    }
}

bool bfs(int val) {
    init();
    queue<int> que;
    visited[fac1] = true;
    que.push(fac1);

    while (!que.empty()) {
        int curr = que.front();
        que.pop();

        for (int i = 0; i < MAP[curr].size(); i++) {
            edge next = MAP[curr][i];
            if (!visited[next.to] && next.val >= val) {
                if (next.to == fac2) return true;
                visited[next.to] = true;
                que.push(next.to);
            }
        }
    }
    return false;
}

int find(int left, int right) {
    if (left == right) return left;
    if (left + 1 == right) {
        if (bfs(right)) return right;
        return left;
    }
    int mid = (left + right) / 2;
    if (bfs(mid)) return find(mid, right);
    return find(left, mid - 1);
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int A, B, C; cin >> A >> B >> C;
        MAP[A].push_back({B, C});
        MAP[B].push_back({A, C});
    }
    cin >> fac1 >> fac2;
    cout << find(1, MAX_VALUE) << endl;
}