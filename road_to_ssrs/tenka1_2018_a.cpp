#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  if (S.size() == 2) {
    cout << S << endl;
  } else {
    cout << string(S.rbegin(), S.rend()) << endl;
  }
}