#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  set<char> st(S.begin(), S.end());
  if (S.size() == st.size()) {
    cout << "yes" << endl;
  } else {
    cout << "no" << endl;
  }
}