#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    while(N--) {
        string input; cin >> input;
        if (input == "Algorithm") cout << "204\n";
        else if (input == "DataAnalysis") cout << "207\n";
        else if (input == "ArtificialIntelligence") cout << "302\n";
        else if (input == "CyberSecurity") cout << "B101\n";
        else if (input == "Network") cout << "303\n";
        else if (input == "Startup") cout << "501\n";
        else if (input == "TestStrategy") cout << "105\n";
    }
}