#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> st;
  for (int i = 0; i < 3; i++) {
    int x;
    cin >> x;
    st.insert(x);
  }
  cout << st.size() << endl;
}