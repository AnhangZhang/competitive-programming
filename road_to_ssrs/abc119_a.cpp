#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int m = stoi(S.substr(5, 2));
  if (m <= 4) {
    cout << "Heisei" << endl;
  } else {
    cout << "TBD" << endl;
  }
}