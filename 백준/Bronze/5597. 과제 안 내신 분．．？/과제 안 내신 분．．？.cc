#include <iostream>

using namespace std;

bool visited[31];

int main() {
    int input;
    for (int i = 0; i < 28; i++) {
        cin >> input;
        visited[input] = true;
    }
    
    for (int i = 1; i <= 30; i++) {
        if (!visited[i]) cout << i << endl;
    }
}