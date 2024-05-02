#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int cnt = 1;
    while (true) {
        int n; cin >> n;
        if (n == 0) break ;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        double med = 0;
        if (n % 2 == 0) med = (v[(n / 2) - 1] + v[n / 2]) / 2.0;
        else med = v[(n - 1) / 2];
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << "Case " << cnt << ": " << med << "\n";
        cnt++;
    }
}