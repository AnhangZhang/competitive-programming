#include <bits/stdc++.h>
using namespace std;
int S(int N) {
  int ans = 0;
  while (N > 0) {
    ans += N % 10;
    N /= 10;
  }
  return ans;
}
int main() {
  int N;
  cin >> N;
  if (N % S(N) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}