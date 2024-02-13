#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

/**
 * ( 는 -1
 * ) 는 -2
 * [ 는 -3
 * ] 는 -4
 */
int calc(string& str) {

    vector<int> st;

    for (char i : str) {
        if (i == '(') st.push_back(-1);
        else if (i == '[') st.push_back(-3);
        else if (i == ')') {
            int current = 0;
            while (true) {
                if (st.empty() || st[st.size() - 1] == -2 || st[st.size() - 1] == -3 || st[st.size() - 1] == -4) return 0;
                if (st[st.size() - 1] == -1) {
                    st.pop_back();
                    if (current == 0) st.push_back(2);
                    else st.push_back(current * 2);
                    break;
                } else {
                    current += st[st.size() - 1];
                    st.pop_back();
                }
            }
        } else {
            int current = 0;
            while (true) {
                if (st.empty() || st[st.size() - 1] == -1 || st[st.size() - 1] == -2 || st[st.size() - 1] == -4) return 0;
                if (st[st.size() - 1] == -3) {
                    st.pop_back();
                    if (current == 0) st.push_back(3);
                    else st.push_back(current * 3);
                    break;
                } else {
                    current += st[st.size() - 1];
                    st.pop_back();
                }
            }
        }
    }
    int ans = 0;
    while (!st.empty()) {
        if (st[st.size() - 1] < 0) return 0;
        ans += st[st.size() - 1];
        st.pop_back();
    }
    return ans;
}

int main() {
    FASTIO
    string str; cin >> str;
    cout << calc(str) << '\n';
}