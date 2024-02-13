#include <iostream>
#include <deque>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main() {
    FASTIO
    deque<int> deq;
    int N; cin >> N;
    while (N--) {
        string cmd; cin >> cmd;
        if (cmd == "push") {
            int num; cin >> num;
            deq.push_back(num);
        } else if (cmd == "pop") {
            if (deq.empty()) cout << "-1\n";
            else {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        } else if (cmd == "size") {
            cout << deq.size() << '\n';
        } else if (cmd == "empty") {
            if (deq.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (cmd == "front") {
            if (deq.empty()) cout << "-1\n";
            else cout << deq.front() << '\n';
        } else if (cmd == "back") {
            if (deq.empty()) cout << "-1\n";
            else cout << deq.back() << '\n';
        }
    }
}