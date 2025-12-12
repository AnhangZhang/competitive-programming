#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    B[i] = i;
  }
  sort(B.begin(), B.end(), [&](int i, int j) { return A[i] < A[j]; });
  for (int i = 0; i < N; i++) {
    cout << B[i] + 1 << " \n"[i == N - 1];
  }
}