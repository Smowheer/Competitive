// Makefile: CXXFLAGS += -std=c++11 -fsanitize=address,undefined -Wall -Werror -Wshadow -O0 -g
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using v3l = vector<vvl>;
using pll = pair<ll,ll>;
using p3l = pair<pll,ll>;
using vb = vector<bool>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl;})

int main() {
  ios::sync_with_stdio(false);
  string dirs; cin >> dirs;
  ll xm[200];
  xm['L'] = -1;
  xm['R'] = 1;
  xm['U'] = 1;
  xm['D'] = -1;
  map<char, char> inv_dir;
  inv_dir['L'] = 'R';
  inv_dir['R'] = 'L';
  inv_dir['U'] = 'D';
  inv_dir['D'] = 'U';
  inv_dir['0'] = '0';
  vector<pll> positions;
  pll current(0, 0);
  ll state = 0;
  ll step = 1;
  char lastdir = '0';
  FOR(i, 0, (ll)(dirs.size())) {
    char d = dirs[i];
    bool xdir = false;
    if (d == 'L' || d == 'R') {
      xdir = true;
    }
    // update state
    if (d == inv_dir[lastdir]) {
      if (state == 0) state = 1;
      else if (state == 1) state = 2;
    } else {
      state = 0;
    }
    // update step
    if (state != 2) step *= 2;
    // update current and positions
    if (xdir) {
      current.xx += xm[d] * step;
      if (state != 2) {
        positions.pb(pll(current.xx + xm[d], current.yy));
      }
    } else {
      current.yy += xm[d] * step;
      if (state != 2) {
        positions.pb(pll(current.xx, current.yy + xm[d]));
      }
    }

    lastdir = d;
  }
  if (state == 2) {
    cout << "impossible" << endl;
    return 0;
  }
  pll last = positions.back();
  cout << -last.xx << " " << -last.yy << endl;
  cout << positions.size() - 1 << endl;
  FOR(i, 0, (ll)(positions.size())-1) {
    pll curr = positions[i];
    cout << curr.xx - last.xx << " " << curr.yy - last.yy << endl;
  }
}
