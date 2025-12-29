#include <bits/stdc++.h>
using namespace std;
int main() {
  int D, F;
  cin >> D >> F;
  while (F + 7 <= D) {
    F += 7;
  }
  cout << F + 7 - D << endl;
}