#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] != "CODEFESTIVAL2016"[i]) {
      ans++;
    }
  }
  cout << ans << endl;
}