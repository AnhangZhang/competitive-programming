#include <bits/stdc++.h>
using namespace std;
int main() {
  int X;
  cin >> X;
  vector<int> dp(X + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < 6; j++) {
      if (i + 100 + j <= X) {
        dp[i + 100 + j] |= dp[i];
      }
    }
  }
  cout << dp[X] << endl;
}