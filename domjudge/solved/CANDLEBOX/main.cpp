#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)

int main() {
  ll D,R,T; cin >> D >> R >> T;
  ll r = 4;
  ll t = 3;
  ll target = R+T;
  ll s = 0;
  ll rs = 0;
  ll ts = 0;
  FOR(i,0,35) {
    rs += r++;
    if (i+1 >= D) ts += t++;
    s = rs + ts;
    if (s >= target) break;
  }
  cout << R - rs << endl;
}
