#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  if (S.size() >= 5 && S.substr(0, 5) == "MUJIN") {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}