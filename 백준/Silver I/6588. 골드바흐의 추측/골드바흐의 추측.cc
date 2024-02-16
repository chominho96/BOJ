#include <iostream>
#include <vector>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 1000010

using namespace std;

int n;
vector<int> PRIME;
bool IS_PRIME[MAX_SIZE];

void init() {
    for (int i = 2; i < MAX_SIZE; i++) IS_PRIME[i] = true;
    for (int i = 2; i * i < MAX_SIZE; i++) {
        if (!IS_PRIME[i]) continue;
        for (int j = i * i; j < MAX_SIZE; j += i) {
            IS_PRIME[j] = false;
        }
    }
    for (int i = 3; i < MAX_SIZE; i++) {
        if (IS_PRIME[i]) PRIME.push_back(i);
    }
}

void calc(int num) {
    int idx = 0;
    while (true) {
        if (PRIME[idx] > num / 2) break;
        if (IS_PRIME[num - PRIME[idx]]) {
            cout << num << " = " << PRIME[idx] << " + " << num - PRIME[idx] << endl;
            return;
        }
        idx++;
    }
    cout << "Goldbach's conjecture is wrong." << endl;
}

int main() {
    FASTIO
    init();
    while (true) {
        cin >> n; if (n == 0) break;
        calc(n);
    }
}