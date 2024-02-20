#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 20010
#define INF 987654321

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

vector<EDGE> MAP[MAX_SIZE];
int DIST[MAX_SIZE];
bool visited[MAX_SIZE];
int V, E, K;

void init() {
    for (int& i : DIST) {
        i = INF;
    }
}

void print() {
    for (int i = 1; i <= V; i++) {
        if (DIST[i] == INF) cout << "INF" << endl;
        else cout << DIST[i] << endl;
    }
}

void dijkstra() {
    DIST[K] = 0;
    priority_queue<EDGE, vector<EDGE>, compare> pq;
    pq.push({K, 0});

    while (!pq.empty()) {
        int curr = pq.top().to;
        int val = pq.top().val;
        pq.pop();

        if (visited[curr]) continue;
        visited[curr] = true;
        DIST[curr] = val;

        for (int i = 0; i < MAP[curr].size(); i++) {
            int next = MAP[curr][i].to;
            int next_val = MAP[curr][i].val;
            if (!visited[next] && DIST[next] > DIST[curr] + next_val) pq.push({next, DIST[curr] + next_val});
        }
    }
}

int main() {
    FASTIO
    cin >> V >> E >> K;
    init();
    for (int i = 0; i < E; i++) {
        int u, v, w; cin >> u >> v >> w;
        MAP[u].push_back({v, w});
    }
    dijkstra();
    print();
}