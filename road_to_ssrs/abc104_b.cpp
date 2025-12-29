#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  bool ok = true;
  if (S[0] != 'A') {
    ok = false;
  }
  int cnt = 0;
  for (int i = 2; i < N - 1; i++) {
    if (S[i] == 'C') {
      cnt++;
    }
  }
  if (cnt != 1) {
    ok = false;
  }
  for (int i = 1; i < N; i++) {
    if (S[i] != 'C') {
      if ('A' <= S[i] && S[i] <= 'Z') {
        ok = false;
      }
    }
  }
  if (ok) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
}