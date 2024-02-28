#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
    FASTIO
    int N, M; cin >> N >> M;
    if (M == 1 || M == 2) cout << "NEWBIE!\n";
    else if (M <= N) cout << "OLDBIE!\n";
    else cout << "TLE!\n";
}