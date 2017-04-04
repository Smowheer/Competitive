#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
  ll n, k;
  vector<ll> peb;
  cin >> n >> k;
  peb.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> peb[i];
  }
  ll days = 0;
  ll remaining_pockets = 0;
  for (int i = 0; i < n; ++i) {
    ll used_pockets = peb[i] / k;
    if (peb[i] % k != 0) used_pockets++;
    days += (used_pockets + remaining_pockets) / 2;
    remaining_pockets = (used_pockets + remaining_pockets) % 2;
  }
  if (remaining_pockets != 0) days++;
  cout << days << endl;
  return 0;
}
