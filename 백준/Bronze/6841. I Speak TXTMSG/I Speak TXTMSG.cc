#include <iostream>
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int main() {
    FASTIO
    while (true) {
        string str; cin >> str;
        if (str == "CU") cout << "see you" << endl;
        else if (str == ":-)") cout << "I’m happy" << endl;
        else if (str == ":-(") cout << "I’m unhappy" << endl;
        else if (str == ";-)") cout << "wink" << endl;
        else if (str == ":-P") cout << "stick out my tongue" << endl;
        else if (str == "(~.~)") cout << "sleepy" << endl;
        else if (str == "TA") cout << "totally awesome" << endl;
        else if (str == "CCC") cout << "Canadian Computing Competition" << endl;
        else if (str == "CUZ") cout << "because" << endl;
        else if (str == "TY") cout << "thank-you" << endl;
        else if (str == "YW") cout << "you’re welcome" << endl;
        else if (str == "TTYL") {
            cout << "talk to you later" << endl;
            break;
        }
        else {
            cout << str << endl;
        }
    }
}