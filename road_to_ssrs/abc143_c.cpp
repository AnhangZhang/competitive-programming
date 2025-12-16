#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  S.erase(unique(S.begin(), S.end()), S.end());
  cout << S.size() << endl;
}