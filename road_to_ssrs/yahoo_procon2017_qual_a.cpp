#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  sort(S.begin(), S.end());
  string T = "yahoo";
  sort(T.begin(), T.end());
  if (S == T) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}