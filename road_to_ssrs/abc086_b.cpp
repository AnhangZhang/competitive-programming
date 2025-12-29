#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int A = stoi(a + b);
  int B = sqrt(A);
  if (B * B == A) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}