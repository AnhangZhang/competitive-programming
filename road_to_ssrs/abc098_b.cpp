#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 1; i < N; i++) {
    set<char> sl;
    for (int j = 0; j < i; j++) {
      sl.insert(S[j]);
    }
    set<char> sr;
    for (int j = i; j < N; j++) {
      sr.insert(S[j]);
    }
    int cnt = 0;
    for (char j = 'a'; j <= 'z'; j++) {
      if (sl.count(j) && sr.count(j)) {
        cnt++;
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}