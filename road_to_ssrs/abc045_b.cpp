#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<string> S(3);
  for (int i = 0; i < 3; i++) {
    cin >> S[i];
  }
  vector<int> P(3);
  int cur = 0;
  while (true) {
    if (P[cur] == S[cur].size()) {
      cout << char('A' + cur) << endl;
      return 0;
    }
    int who = S[cur][P[cur]] - 'a';
    P[cur]++;
    cur = who;
  }
}