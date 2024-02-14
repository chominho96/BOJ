#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 100010
#define INF 987654321

using namespace std;

int NUMBER[4];
int MIN[4];
int MAX[4];
int N;

void init() {
    cin >> NUMBER[1] >> NUMBER[2] >> NUMBER[3];
    for (int i = 1; i <= 3; i++) {
        MIN[i] = NUMBER[i];
        MAX[i] = NUMBER[i];
    }
}

void dp() {
    int min1 = min(MIN[1] + NUMBER[1], MIN[2] + NUMBER[1]);
    int min2 = min(MIN[1] + NUMBER[2], min(MIN[2] + NUMBER[2], MIN[3] + NUMBER[2]));
    int min3 = min(MIN[2] + NUMBER[3], MIN[3] + NUMBER[3]);
    MIN[1] = min1; MIN[2] = min2; MIN[3] = min3;

    int max1 = max(MAX[1] + NUMBER[1], MAX[2] + NUMBER[1]);
    int max2 = max(MAX[1] + NUMBER[2], max(MAX[2] + NUMBER[2], MAX[3] + NUMBER[2]));
    int max3 = max(MAX[2] + NUMBER[3], MAX[3] + NUMBER[3]);
    MAX[1] = max1; MAX[2] = max2; MAX[3] = max3;
}

int main() {
    FASTIO
    cin >> N; init();
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> NUMBER[j];
        }
        dp();
    }
    cout << max(max(MAX[1], MAX[2]), MAX[3]) << ' '
        << min(min(MIN[1], MIN[2]), MIN[3]) << '\n';
}