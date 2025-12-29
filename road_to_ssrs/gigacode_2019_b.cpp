#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, X, Y, Z;
  cin >> N >> X >> Y >> Z;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    if (A >= X && B >= Y && A + B >= Z) {
      ans++;
    }
  }
  cout << ans << endl;
}