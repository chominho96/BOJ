#include <iostream>
#include <algorithm>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 5000
#define MAX_SIZE_2 16000010

using namespace std;

long long N;
long long A[MAX_SIZE];
long long B[MAX_SIZE];
long long C[MAX_SIZE];
long long D[MAX_SIZE];

long long A_B[MAX_SIZE_2];
long long C_D[MAX_SIZE_2];

void add(long long* arr1, long long* arr2, long long* arr3) {
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr3[idx++] = arr1[i] + arr2[j];
        }
    }
}

long long calc() {
    long long ans = 0;
    long long left = 0;
    long long right = N * N - 1;
    while (true) {
        if (left >= N * N || right < 0) break;
        if (A_B[left] + C_D[right] == 0) {
            long long l = 0; long long r = 0;
            for (long long i = left; i < N * N; i++) {
                if (A_B[i] == A_B[left]) l++;
                else break;
            }
            for (long long i = right; i >= 0; i--) {
                if (C_D[i] == C_D[right]) r++;
                else break;
            }
            ans += l * r;
            left += l;
            right -= r;
        }
        else if (A_B[left] + C_D[right] > 0) right--;
        else if (A_B[left] + C_D[right] < 0) left++;
    }
    return ans;
}

int main() {
    FASTIO
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    add(A, B, A_B);
    add(C, D, C_D);
    sort(A_B, A_B + N * N);
    sort(C_D, C_D + N * N);
    cout << calc() << '\n';
}