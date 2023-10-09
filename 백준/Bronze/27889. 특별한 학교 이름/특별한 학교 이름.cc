#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;
    
    if (input == "NLCS") cout << "North London Collegiate School\n";
    else if (input == "BHA") cout << "Branksome Hall Asia\n";
    else if (input == "KIS") cout << "Korea International School\n";
    else if (input == "SJA") cout << "St. Johnsbury Academy\n";
}