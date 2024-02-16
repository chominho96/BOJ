#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int mo1, mo2, za1, za2;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b , a % b);
}

void sum() {
    int mo = mo1 * mo2;
    int za = za1 * mo2 + za2 * mo1;
    int g = gcd(mo, za);
    cout << za / g << ' ' << mo / g << endl;
}

int main() {
    FASTIO
    cin >> za1 >> mo1 >> za2 >> mo2;
    sum();
}