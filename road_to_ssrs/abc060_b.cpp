#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> used(B);
  int cur = 0;
  while (true) {
    cur += A;
    cur %= B;
    if (used[cur]) {
      break;
    }
    used[cur] = 1;
  }
  if (used[C]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}