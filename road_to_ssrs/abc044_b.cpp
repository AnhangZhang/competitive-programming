#include <bits/stdc++.h>
using namespace std;
int main() {
  string w;
  cin >> w;
  vector<int> cnt(26);
  for (int i = 0; i < w.size(); i++) {
    cnt[w[i] - 'a']++;
    cnt[w[i] - 'a'] %= 2;
  }
  if (accumulate(cnt.begin(), cnt.end(), 0) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}