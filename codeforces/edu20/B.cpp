#include <bits/stdc++.h>
using namespace std;

int main() {
  int l;
  cin >> l;
  vector<int> vi;
  vi.assign(l, 1 << 20);
  for (int i = 0; i < l; ++i) {
    int tmp;
    cin >> tmp;
    if (tmp == 0) {
      vi[i] = 0;
    }
  }
  bool init = false;
  int cur = 0;
  int bcur = 0;
  for (int i = 0; i < l; ++i) {
    if (init) {
      cur++;
      vi[i] = min(vi[i], cur);
    }
    if (vi[i] == 0) {
      init = true;
      cur = 0;
      if (i > 0) {
        bcur = 0;
        for (int k = i-1; k >= 0; --k) {
          if (vi[k] == 0) break;
          bcur++;
          vi[k] = min(vi[k], bcur);
        }
      }
    }
  }
  for (int i = 0; i < l; ++i) {
    cout << vi[i] << " ";
  }
  cout << endl;

  return 0;
}
