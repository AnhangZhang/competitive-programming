#include <bits/stdc++.h>
using namespace std;
int main() {
  int s;
  cin >> s;
  map<int, bool> used;
  used[s] = true;
  for (int i = 2; true; i++) {
    if (s % 2 == 0) {
      s /= 2;
    } else {
      s = s * 3 + 1;
    }
    if (used[s]) {
      cout << i << endl;
      return 0;
    }
    used[s] = true;
  }
}