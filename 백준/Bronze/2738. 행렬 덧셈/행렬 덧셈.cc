#include <iostream>
#define MAX_SIZE 101

using namespace std;

int A[MAX_SIZE][MAX_SIZE];
int N, M, input;

int main() {
    
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> input;
            A[i][j] += input;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }
}