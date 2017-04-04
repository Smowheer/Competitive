#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main() {
  ll b,q,l,m;
  cin >> b >> q >> l >> m;
  set<ll> nums;
  for (int i = 0; i < m; ++i) {
    ll ins;
    cin >> ins;
    nums.insert(ins);
  }
  if (abs(b) > l) {
    cout << "0" << endl;
    return 0;
  }
  if ((q == 0 && nums.count(0)==0) ||
      (q == 1 && nums.count(b)==0) ||
      (q == -1&& (nums.count(b)==0 || nums.count(-b)==0))) {
    cout << "inf" << endl;
    return 0;
  }
  if (q == 0) {
    cout << 1 - nums.count(b) << endl;
    return 0;
  }
  if (q == 1) {
    cout << 1 - nums.count(b) << endl;
    return 0;
  }
  if (q == -1) {
    cout << "0" << endl;
    return 0;
  }
  ll prin = 0;
  ll cur = b;
  while (true) {
    if (abs(cur) > l) break;
    //cout << cur << endl;
    if (nums.count(cur)==0) prin++;
    cur *= q;
  }
  cout << prin << endl;
  return 0;
}
