#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int N = S.size() - 1;
  while (N > 0) {
    if (N % 2 == 0) {
      string T = S.substr(0, N / 2);
      string U = S.substr(N / 2, N / 2);
      if (T == U) {
        cout << N << endl;
        return 0;
      }
    }
    N--;
  }
}