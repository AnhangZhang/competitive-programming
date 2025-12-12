#include <bits/stdc++.h>
using namespace std;
int main() {
  for (int i = 0; i < 3; i++) {
    string S;
    cin >> S;
    cout << char(S[0] - 'a' + 'A');
  }
  cout << endl;
}