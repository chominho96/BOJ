#include <iostream>
#include <iomanip>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 51

using namespace std;

int M, K, N = 0;
int NUMBER[MAX_SIZE];

double func(int idx) {
    if (NUMBER[idx] < K) return 0.0;
    double result = 1.0;
    int num = NUMBER[idx];
    int tot = N;
    for (int i = 1; i <= K; i++) {
        result *= (double) num-- / (double) tot--;
    }
    return result;
}


double calc() {
    double result = 0;
    for (int i = 1; i <= M; i++) {
        result += func(i);
    }
    return result;
}

int main() {
    FASTIO
    cin >> M;
    for (int i = 1; i <= M; i++) {
        cin >> NUMBER[i];
        N += NUMBER[i];
    }
    cin >> K;
    cout << setprecision(15);
    cout << fixed;
    cout << calc() << endl;
}