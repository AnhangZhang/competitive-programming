#include <bits/stdc++.h>
using namespace std;
int main() {
  int X;
  cin >> X;
  int ans = 1;
  for (int i = 2; i <= X; i++) {
    int b = i;
    if (b * b > X) {
      break;
    }
    while (b * i <= X) {
      b *= i;
    }
    ans = max(ans, b);
  }
  cout << ans << endl;
}