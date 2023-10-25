#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N; cin >> N;
    long long ans1 = 0;
    long long ans2 = 0;
    for (int i = 1; i <= N; i++) {
        ans1 += i;
        ans2 += pow(i, 3);
    }
    cout << ans1 << endl << ans1 * ans1 << endl << ans2 << endl;
}