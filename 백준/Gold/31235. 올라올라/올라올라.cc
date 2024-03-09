#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 1000001

using namespace std;

int N;

int main() {
    FASTIO
    cin >> N;

    int c_max = 0;
    int num;
    int ans = 1;
    int cur = 1;
    bool flag = false;
    for (int i = 1; i <= N; i++) {
        cin >> num;
        if (flag) {
            if (num >= c_max) {
                ans = max(ans, cur);
                c_max = num;
                flag = false;
            }
            else {
                cur++;
            }
        }
        else {
            if (num >= c_max) c_max = num;
            else {
                cur = 2;
                flag = true;
            }
        }
    }
    cout << max(ans, cur) << endl;
}