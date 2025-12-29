#include <bits/stdc++.h>
using namespace std;
int main() {
  int X, Y, Z;
  cin >> X >> Y >> Z;
  int cnt = 1;
  while (true) {
    if (cnt * (Y + Z) + Z > X) {
      break;
    }
    cnt++;
  }
  cout << cnt - 1 << endl;
}