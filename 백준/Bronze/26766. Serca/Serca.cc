#include <iostream>

using namespace std;

void func() {
    cout << " @@@   @@@ \n";
    cout << "@   @ @   @\n";
    cout << "@    @    @\n";
    cout << "@         @\n";
    cout << " @       @ \n";
    cout << "  @     @  \n";
    cout << "   @   @   \n";
    cout << "    @ @    \n";
    cout << "     @     \n";
}

int main() {
    int N; cin >> N;
    while (N--) {
        func();
    }
}