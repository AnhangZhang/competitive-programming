#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int ans = 1;
  for (int i = 0; i < N; i++) {
    ans *= 4;
  }
  cout << ans << endl;
}