#include <iostream>
#include <cmath>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 10000010

using namespace std;

int N;
bool IS_PRIME[MAX_SIZE];
int PRIME = 1;

void init() {
    for (int i = 2; i < MAX_SIZE; i++) IS_PRIME[i] = true;
    for (int i = 2; i <= sqrt(MAX_SIZE); i++) {
        if (!IS_PRIME[i]) continue;
        for (int j = i * i; j < MAX_SIZE; j += i) {
            IS_PRIME[j] = false;
        }
    }
}

void next_prime() {
    for (int i = PRIME + 1; i < MAX_SIZE; i++) {
        if (IS_PRIME[i]) {
            PRIME = i;
            return;
        }
    }
}

void calc() {
    while (N != 1) {
        next_prime();
        while (N % PRIME == 0) {
            N /= PRIME;
            cout << PRIME << endl;
        }
    }
}

int main() {
    FASTIO
    cin >> N;
    init(); calc();
}