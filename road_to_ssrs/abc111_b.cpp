#include <bits/stdc++.h>
using namespace std;
bool f(int N) {
  vector<int> ans;
  while (N > 0) {
    ans.push_back(N % 10);
    N /= 10;
  }
  sort(ans.begin(), ans.end());
  return ans.front() == ans.back();
}
int main() {
  int N;
  cin >> N;
  while (f(N) == false) {
    N++;
  }
  cout << N << endl;
}