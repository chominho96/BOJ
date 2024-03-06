#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
    FASTIO
    int N; cin >> N;
    if (N == 1) cout << "12 1600" << endl;
    else if (N == 2) cout << "11 894" << endl;
    else if (N == 3) cout << "11 1327" << endl;
    else if (N == 4) cout << "10 1311" << endl;
    else if (N == 5) cout << "9 1004" << endl;
    else if (N == 6) cout << "9 1178" << endl;
    else if (N == 7) cout << "9 1357" << endl;
    else if (N == 8) cout << "8 837" << endl;
    else if (N == 9) cout << "7 1055" << endl;
    else if (N == 10) cout << "6 556" << endl;
    else if (N == 11) cout << "6 773" << endl;
}