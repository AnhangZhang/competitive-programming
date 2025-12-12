#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  cout << 4 - 2 * count(S.begin(), S.end(), '-') << endl;
}