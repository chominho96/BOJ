#include <iostream>
#include <queue>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FASTIO
    int N; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (N--) {
        int x; cin >> x;
        if (x == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(x);
        }
    }
}