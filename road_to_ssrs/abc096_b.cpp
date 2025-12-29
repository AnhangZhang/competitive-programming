#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int K;
  cin >> K;
  if (A > C) {
    swap(A, C);
  }
  if (B > C) {
    swap(B, C);
  }
  for (int i = 0; i < K; i++) {
    C *= 2;
  }
  cout << A + B + C << endl;
}