#include <bits/stdc++.h>
using namespace std;
int main() {
  string S, T;
  cin >> S >> T;
  int N = S.size();
  S += S;
  for (int i = 0; i < N; i++) {
    if (S.substr(i, N) == T) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}