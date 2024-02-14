#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 100

using namespace std;

long long FIBO[MAX_SIZE];

long long fibo(int n) {
    if (n <= 1) return n;
    if (FIBO[n] > 0) return FIBO[n];
    return FIBO[n] = fibo(n - 1) + fibo(n - 2);
}

int main() {
    int n; cin >> n;
    cout << fibo(n) << '\n';
}