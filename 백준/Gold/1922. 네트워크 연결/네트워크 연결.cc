#include <iostream>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 1010

using namespace std;

struct EDGE {
    int to;
    int val;
};

struct compare {
    bool operator()(const EDGE& e1, const EDGE& e2) {
        return e1.val > e2.val;
    }
};

int N, M;
vector<EDGE> MAP[MAX_SIZE];
bool visited[MAX_SIZE];

int dijkstra(int start) {
    priority_queue<EDGE, vector<EDGE>, compare> pq;
    visited[start] = true;
    for (int i = 0; i < MAP[start].size(); i++) {
        pq.push(MAP[start][i]);
    }

    int result = 0;
    for (int i = 0; i < N - 1; i++) {
        EDGE edge;
        while (true) {
            edge = pq.top();
            pq.pop();
            if (!visited[edge.to]) break;
        }
        visited[edge.to] = true;
        result += edge.val;

        for (int j = 0; j < MAP[edge.to].size(); j++) {
            int next = MAP[edge.to][j].to;
            int val = MAP[edge.to][j].val;
            if (!visited[next]) pq.push({next, val});
        }
    }

    return result;
}

int main() {
    FASTIO
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
           int a, b, c; cin >> a >> b >> c;
           if (a != b) {
               MAP[a].push_back({b, c});
               MAP[b].push_back({a, c});
           }
    }
    cout << dijkstra(1) << endl;
}