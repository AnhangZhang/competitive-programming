#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  int ans = 0;
  while (ans + B <= A) {
    ans += B;
  }
  cout << ans << endl;
}