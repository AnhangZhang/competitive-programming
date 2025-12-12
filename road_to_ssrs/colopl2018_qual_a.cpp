#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  string S;
  cin >> S;
  if (A <= S.size() && S.size() <= B) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}