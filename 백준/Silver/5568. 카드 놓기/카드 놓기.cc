#include <iostream>
#include <set>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 11

using namespace std;

int n, k;
set<long long> st;

long long NUMBER[MAX_SIZE];
bool visited[MAX_SIZE];

void dp(int idx, long long value, int cnt) {
    if (visited[idx]) return;
    if (cnt == k) {
        st.insert(value);
        return;
    }
    visited[idx] = true;
    for (int i = 1; i <= n; i++) {
        dp(i, stoll(to_string(value) + to_string(NUMBER[i])), cnt + 1);
    }
    visited[idx] = false;
}

void init() {
    for (int i = 1; i <= n; i++) {
        dp(i, NUMBER[i], 1);
    }
}

int main() {
    FASTIO
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> NUMBER[i];
    }
    init();
    cout << st.size() << endl;
}