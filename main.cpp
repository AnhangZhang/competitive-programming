#include "library/my_template.hpp"
#include "library/other/io.hpp"

signed main() {
  STR(S);
  int ANS = 0;
  ANS += count(all(S), 'i');
  ANS += count(all(S), 'j');
  print(ANS);

  vi ans(2, 1);
  SHOW(ans);
  SHOW(S);
  return 0;
}