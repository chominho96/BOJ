#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 510
#define INF 9999987654321

typedef long long ll;
using namespace std;

struct _EDGE {
    ll from;
    ll to;
    ll val;
};

vector<_EDGE> EDGE;
ll DIST[MAX_SIZE];
ll N, M;

void init() {
    for (ll i = 0; i < MAX_SIZE; i++) {
        DIST[i] = INF;
    }
}

void bell() {
    DIST[1] = 0;
    for (ll i = 0; i < N - 1; i++) {
        for (ll j = 0; j < EDGE.size(); j++) {
            ll from = EDGE[j].from;
            ll to = EDGE[j].to;
            ll val = EDGE[j].val;
            if (DIST[from] == INF) continue;
            DIST[to] = min(DIST[from] + val, DIST[to]);
        }
    }
    for (ll j = 0; j < EDGE.size(); j++) {
        ll from = EDGE[j].from;
        ll to = EDGE[j].to;
        ll val = EDGE[j].val;
        if (DIST[to] == INF) continue;
        if (DIST[to] > DIST[from] + val) {
            cout << -1 << endl;
            exit(0);
        }
    }
}

void print() {
    for (ll i = 2; i <= N; i++) {
        if (DIST[i] == INF) cout << -1 << endl;
        else cout << DIST[i] << endl;
    }
}

int main() {
    FASTIO
    init();
    cin >> N >> M;
    for (ll i = 0; i < M; i++) {
        ll A, B, C; cin >> A >> B >> C;
        EDGE.push_back({A, B, C});
    }
    bell();
    print();
}