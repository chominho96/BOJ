#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int L, A, B, C, D; cin >> L >> A >> B >> C >> D;
    int kor = A % C == 0 ? A / C : A / C + 1;
    int eng = B % D == 0 ? B / D : B / D + 1;
    cout << L - max(kor, eng) << '\n';
}