#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  reverse(t.begin(), t.end());
  for (int i = 0; i < min(n, m); i++) {
    if (s[i] < t[i]) {
      cout << "Yes" << endl;
      return 0;
    } else if (s[i] > t[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (n < m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}