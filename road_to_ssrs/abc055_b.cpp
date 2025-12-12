#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  long long ans = 1;
  for (int i = 0; i < N; i++) {
    ans = ans * (i + 1) % MOD;
  }
  cout << ans << endl;
}