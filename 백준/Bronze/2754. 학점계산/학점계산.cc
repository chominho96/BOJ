#include <iostream>

using namespace std;

int main() {
    string input; cin >> input;
    if (input == "A+") cout << "4.3\n";
    if (input == "A0") cout << "4.0\n";
    if (input == "A-") cout << "3.7\n";
    if (input == "B+") cout << "3.3\n";
    if (input == "B0") cout << "3.0\n";
    if (input == "B-") cout << "2.7\n";
    if (input == "C+") cout << "2.3\n";
    if (input == "C0") cout << "2.0\n";
    if (input == "C-") cout << "1.7\n";
    if (input == "D+") cout << "1.3\n";
    if (input == "D0") cout << "1.0\n";
    if (input == "D-") cout << "0.7\n";
    if (input == "F") cout << "0.0\n";
}