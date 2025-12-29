#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  string lst = "";
  map<string, bool> used;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    if (used[s]) {
      cout << "No" << endl;
      return 0;
    }
    used[s] = true;
    if (lst != "" && lst.back() != s[0]) {
      cout << "No" << endl;
      return 0;
    }
    lst = s;
  }
  cout << "Yes" << endl;
}