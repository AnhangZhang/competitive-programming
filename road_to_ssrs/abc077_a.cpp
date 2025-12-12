#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> C(2);
  for (int i = 0; i < 2; i++) {
    cin >> C[i];
  }
  bool ok = true;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      if (C[i][j] != C[1 - i][2 - j]) {
        ok = false;
      }
    }
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}