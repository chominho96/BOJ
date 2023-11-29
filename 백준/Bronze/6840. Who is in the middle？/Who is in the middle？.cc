#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int> pq;
    for (int i = 0; i < 3; i++) {
        int N; cin >> N;
        pq.push(N);
    }
    pq.pop();
    cout << pq.top() << '\n';
}