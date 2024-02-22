#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 110
#define MAX 25

using namespace std;

int N;
long long NUMBER[MAX_SIZE];
long long DP[MAX][2];
int flag = 0;       // 현재 flag의 값을 이용

void dp() {

    DP[0][0] = 1;
    for (int i = 1; i < N; i++)  {

        // flag가 아닌 값 다 지우기
        for (int j = 0; j <= 20; j++) {
            DP[j][1 - flag] = 0;
        }

        if (NUMBER[i] == 0) {
            if (i == 1) {
                DP[0][1] = 1;
            }
            else {
                for (int j = 0; j <= 20; j++) {
                    DP[j][1 - flag] = DP[j][flag] * 2;
                }
            }
        }
        else {
            for (int j = 0; j <= 20; j++) {
                long long cnt = DP[j][flag]; // j가 나올 경우의 수
                long long right = j + NUMBER[i];
                long long left = j - NUMBER[i];

                if (right >= 0 && right <= 20) {
                    DP[right][1 - flag] += cnt;
                }
                if (left >= 0 && left <= 20) {
                    DP[left][1 - flag] += cnt;
                }
            }
        }


        flag = 1 - flag;
    }
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> NUMBER[i];
    }
    dp();
    cout << DP[NUMBER[N]][flag] << endl;
}