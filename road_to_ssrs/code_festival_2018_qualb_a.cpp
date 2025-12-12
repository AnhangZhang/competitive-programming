#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    if (i % N == 0) {
      ans++;
    }
  }
  cout << 100 - ans << endl;
}