#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B;
  cin >> A >> B;
  if (A == B) {
    cout << A * 2 << endl;
  } else {
    cout << max(A, B) * 2 - 1 << endl;
  }
}