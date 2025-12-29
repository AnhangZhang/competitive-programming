#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;
  int N = S.size();
  if (A + B + 1 != N) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < N; i++) {
    if (i == A && S[i] != '-') {
      cout << "No" << endl;
      return 0;
    }
    if (i != A && !('0' <= S[i] && S[i] <= '9')) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}