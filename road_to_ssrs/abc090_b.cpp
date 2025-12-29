#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  int ans = 0;
  for (int i = A; i <= B; i++) {
    string S = to_string(i);
    string T = S;
    reverse(T.begin(), T.end());
    if (S == T) {
      ans++;
    }
  }
  cout << ans << endl;
}