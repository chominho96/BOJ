#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 1000001

using namespace std;

int NUMBER[MAX_SIZE];
int ANS[MAX_SIZE];
int N;

void calc() {
    int idx = N;
    int val = -1;
    for (int i = N; i >= 1; i--) {
        if (NUMBER[i] != NUMBER[idx]) {
            idx = i;
            val = i + 1;
        }
        ANS[i] = val;
    }
}

void print() {
    for (int i = 1; i <= N; i++) {
        cout << ANS[i] << ' ';
    }
    cout << endl;
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> NUMBER[i];
    }
    calc();
    print();
}