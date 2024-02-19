#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 1000010

using namespace std;

int n, m;
int PARENT[MAX_SIZE];

void init() {
    for (int i = 0; i < MAX_SIZE; i++) {
        PARENT[i] = i;
    }
}

int find(int a) {
    if (PARENT[a] == a) return a;
    else return PARENT[a] = find(PARENT[a]);
}

void sum(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (a < b) PARENT[b] = a;
        else PARENT[a] = b;
    }
}

int main() {
    FASTIO
    init();
    cin >> n >> m;
    while (m--) {
        int cmd, a, b; cin >> cmd >> a >> b;
        if (cmd == 0) {
            sum(a, b);
        } else {
            if (find(a) == find(b)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}