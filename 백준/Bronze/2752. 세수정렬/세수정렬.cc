#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 3; i++) {
        int n; cin >> n; pq.push(n);
    }
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
}