#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  string S;
  cin >> N >> S;
  for (int i = 0; i < S.size(); i++) {
    int t = S[i] - 'A';
    t = (t + N) % 26;
    S[i] = char('A' + t);
  }
  cout << S << endl;
}