#include <iostream>
#define INF 987654321

using namespace std;

int main() {
    int N, A, B; cin >> N >> A >> B;
    int S = B >= N ? B : INF;
    
    if (A < S) cout << "Bus\n";
    else if (A == S) cout << "Anything\n";
    else cout << "Subway\n";
}