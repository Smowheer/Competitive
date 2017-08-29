#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T;
int arr[10010];
int lis[10010];
int lis_pre[10010];
bool nocut[10010];
int main() {
  cin >> T;
  for (int t = 0; t < T; ++t) {
    memset(nocut, 0, sizeof(nocut));
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> arr[i];
    }
    int si = 1;
    for (int i = 1; i <= n; ++i) {
      int pre = 0;
      int pre_max = 0;
      for (int j = 1; j < i; ++j) {
        if (arr[j] < arr[i] && lis[j] > pre_max) {
          pre = j;
          pre_max  = lis[j];
        }
      }
      lis_pre[i] = pre;
      lis[i] = pre_max + 1;
      if (lis[i] > lis[si]) si = i;
    }
    if (lis[si] == n) {
      cout << "none" << endl;
    } else {
      int cc = 0;
      while (true) {
        nocut[si] = true;
        cc++;
        si = lis_pre[si];
        if (si == 0) break;
      }
      cc = n - cc;
      bool el = true;
      for (int i = 1; i <= n; ++i) {
        if (!nocut[i]) {
          cout << i;
          cc--;
          if (cc != 0) {
            cout << " ";
          } else {
            el = false;
            cout << endl;
          }
        }
        if (el && i == n) cout << endl;
      }
    }
  }
}
