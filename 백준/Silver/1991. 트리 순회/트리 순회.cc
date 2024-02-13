#include <iostream>
#include <utility>

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 30

using namespace std;

pair<int, int> TREE[MAX_SIZE];
int N;

void pre(int idx) {
    if (idx == 0) return;
    cout << char('A' + idx - 1);
    pre(TREE[idx].first);
    pre(TREE[idx].second);
}

void in(int idx) {
    if (idx == 0) return;
    in(TREE[idx].first);
    cout << char('A' + idx - 1);
    in(TREE[idx].second);
}

void post(int idx) {
    if (idx == 0) return;
    post(TREE[idx].first);
    post(TREE[idx].second);
    cout << char('A' + idx - 1);
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        char parent, left, right;
        cin >> parent >> left >> right;
        if (left != '.') TREE[parent - 'A' + 1].first = left - 'A' + 1;
        if (right != '.') TREE[parent - 'A' + 1].second = right - 'A' + 1;
    }

    pre(1);
    cout << '\n';
    in(1);
    cout << '\n';
    post(1);
    cout << '\n';
}