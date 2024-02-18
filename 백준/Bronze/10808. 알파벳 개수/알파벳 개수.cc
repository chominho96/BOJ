#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define MAX_SIZE 30

using namespace std;

int ALPHA[MAX_SIZE];

int main() {
    FASTIO
    string str; cin >> str;
    for (int i = 0; i < str.size(); i++) {
        ALPHA[str[i] - 'a']++;   
    }
    for (char i = 'a'; i <= 'z'; i++) {
        cout << ALPHA[i - 'a'] << ' ';
    }
    cout << endl;
}