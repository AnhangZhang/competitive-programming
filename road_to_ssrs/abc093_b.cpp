#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, K;
  cin >> A >> B >> K;
  vector<int> ans;
  for (int i = A; i < A + K; i++) {
    if (A <= i && i <= B) {
      ans.push_back(i);
    }
  }
  for (int i = B - K + 1; i <= B; i++) {
    if (A <= i && i <= B) {
      ans.push_back(i);
    }
  }
  sort(ans.begin(), ans.end());
  ans.erase(unique(ans.begin(), ans.end()), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
}