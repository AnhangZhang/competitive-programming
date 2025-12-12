#include <bits/stdc++.h>
using namespace std;
int main() {
  int ans = 0;
  for (int i = 0; i < 8; i++) {
    int x;
    cin >> x;
    ans = max(ans, x);
  }
  cout << ans << endl;
}