#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int C = -1;
  int F = -1;
  for (int i = 0; i < S.size(); i++) {
    if (C == -1 && S[i] == 'C') {
      C = i;
    }
    if (S[i] == 'F') {
      F = i;
    }
  }
  if (C != -1 && F != -1 && C < F) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}