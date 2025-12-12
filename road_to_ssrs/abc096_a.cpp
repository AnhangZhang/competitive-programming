#include <bits/stdc++.h>
using namespace std;
const vector<int> M = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  int a, b;
  cin >> a >> b;
  int m = 1, d = 1;
  int ans = 0;
  while (true) {
    if (m == d) {
      ans++;
    }
    if (m == a && d == b) {
      break;
    }
    d++;
    if (d > M[m]) {
      m++;
      d = 1;
    }
  }
  cout << ans << endl;
}