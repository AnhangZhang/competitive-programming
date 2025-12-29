#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  int ans = 0;
  for (int i = max(A, C); i < min(B, D); i++) {
    if (A <= i && i < B && C <= i && i < D) {
      ans++;
    }
  }
  cout << ans << endl;
}