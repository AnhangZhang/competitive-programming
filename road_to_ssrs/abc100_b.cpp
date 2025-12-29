#include <bits/stdc++.h>
using namespace std;
int main() {
  int D, N;
  cin >> D >> N;
  int S = 1;
  if (D == 1) {
    S *= 100;
  }
  if (D == 2) {
    S *= 10000;
  }
  vector<int> A;
  for (int i = S; A.size() < N; i += S) {
    int cnt = 0;
    int cur = i;
    while (cur % 100 == 0) {
      cur /= 100;
      cnt++;
    }
    if (cnt == D) {
      A.push_back(i);
    }
  }
  cout << A[N - 1] << endl;
}