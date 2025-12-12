#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  for (int i = 0; i < 3; i++) {
    S[i] = S[i] ^ '1' ^ '9';
  }
  cout << S << endl;
}