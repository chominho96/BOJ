#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

string S;
int K = 0;
int P = 0;

int calc() {
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'K') {
            K++;
            if (P > 0) P--;
        }
        if (S[i] == 'P') {
            P++;
            if (K > 0) K--;
        }
    }
    return K + P;
}

int main() {
    FASTIO
    cin >> S;
    cout << calc() << endl;
}