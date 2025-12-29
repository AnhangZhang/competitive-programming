#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, x;
  cin >> a >> b >> x;
  long long l = a / x * x;
  if (l < a) {
    l += x;
  }
  long long r = b / x * x;
  if (a <= l && l <= b && a <= r && r <= b) {
    cout << r / x - l / x + 1 << endl;
  } else {
    cout << 0 << endl;
  }
}