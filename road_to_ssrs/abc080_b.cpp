#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  auto f = [&](int n) -> int {
    int ans = 0;
    while (n > 0) {
      ans += n % 10;
      n /= 10;
    }
    return ans;
  };
  if (N % f(N) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}