#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<int> cnt(27);
  for (int i = 0; i < N; i++) {
    cnt[S[i] - 'a']++;
  }
  int cur = 0;
  while (cnt[cur] > 0) {
    cur++;
  }
  if (cur < 26) {
    cout << char(cur + 'a') << endl;
  } else {
    cout << "None" << endl;
  }
}