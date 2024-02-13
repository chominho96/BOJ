#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

vector<int> st;

int main() {
    FASTIO
    int N; cin >> N;
    while (N--) {
        string input;
        cin >> input;
        if (input == "push") {
            int num; cin >> num; st.push_back(num);
        } else if (input == "pop") {
            if (st.empty()) cout << "-1\n";
            else {
                cout << st[st.size() - 1] << '\n';
                st.pop_back();
            }
        } else if (input == "size") {
            cout << st.size() << '\n';
        } else if (input == "empty") {
            if (st.empty()) cout << "1\n";
            else cout << "0\n";
        } else if (input == "top") {
            if (st.empty()) cout << "-1\n";
            else cout << st[st.size() - 1] << '\n';
        }
    }
}