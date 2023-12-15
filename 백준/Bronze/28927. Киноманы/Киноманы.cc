#include <iostream>

using namespace std;

int main() {

  int t1, e1, f1, t2, e2, f2;
  cin >> t1 >> e1 >> f1 >> t2 >> e2 >> f2;

  int maxTime = 3 * t1 + 20 * e1 + 120 * f1;
  int melTime = 3 * t2 + 20 * e2 + 120 * f2;

  if (maxTime > melTime) cout << "Max\n";
  else if (maxTime < melTime) cout << "Mel\n";
  else cout << "Draw\n";

  return 0;
}
