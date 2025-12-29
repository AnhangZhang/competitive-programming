#include <bits/stdc++.h>
using namespace std;
int main() {
  int S = 0;
  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    S += x;
  }
  if (S >= 22) {
    cout << "bust" << endl;
  } else {
    cout << "win" << endl;
  }
}