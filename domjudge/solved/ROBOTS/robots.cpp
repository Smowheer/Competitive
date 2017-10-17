#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
#define xx first
#define yy second
#define FOR(i,a,b) for(ll i=(a); i<(b); ++i)

vvl rev_r;
vvl rev_g;
ll T, N, dummy;
//set<pll> matchable;
vector<vector<bool>> matchable;
queue<pll> unhandled;

void do_stuff(vvl &arr, ll i) {
  if ((ll)arr[i].size() >= 2) {
    FOR(j,0,(ll)arr[i].size()-1) {
      FOR(k, j+1, (ll)arr[i].size()) {
        ll a = arr[i][j];
        ll b = arr[i][k];
        if (!matchable[a][b]) {
          unhandled.push(make_pair(a,b));
          matchable[a][b] = true;
          matchable[b][a] = true;
        }
      }
    }
  }
}
void do_stuff2(vvl &arr, ll x, ll y) {
  FOR(j,0,(ll)arr[x].size()) {
    FOR(k, 0, (ll)arr[y].size()) {
      ll a = arr[x][j];
      ll b = arr[y][k];
      if (!matchable[a][b]) {
        unhandled.push(make_pair(a,b));
        matchable[a][b] = true;
        matchable[b][a] = true;
      }
    }
  }
}

int main() {
  cin >> T;
  while (T-->0) {
    ll t; cin >> t >> N;
    rev_r.clear(); rev_r.resize(N);
    rev_g.clear(); rev_g.resize(N);
    matchable = vector<vector<bool>>(N, vector<bool>(N, false));
    while (!unhandled.empty()) unhandled.pop();
    FOR(i,0,N) {
      cin >> dummy;
      rev_r[dummy].push_back(i);
    }
    FOR(i,0,N) {
      cin >> dummy;
      rev_g[dummy].push_back(i);
    }
    FOR(i,0,N) {
      do_stuff(rev_r, i);
      do_stuff(rev_g, i);
    }
    while (!unhandled.empty()) {
      pll cur = unhandled.front(); unhandled.pop();
      do_stuff2(rev_r, cur.xx, cur.yy);
      do_stuff2(rev_g, cur.xx, cur.yy);
    }
    bool ok = true;
    FOR(i,0,N) FOR(j,i+1,N) if (!matchable[i][j]) ok = false;

    if (ok) {
      cout << t << " YES" << endl;
    } else {
      cout << t << " NO" << endl;
    }
  }
}
