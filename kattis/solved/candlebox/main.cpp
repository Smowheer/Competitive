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

ll Sig(ll n) {
  return (n * (n+1)) / 2;
}

int main() {
  ios::sync_with_stdio(false);
  ll D, R, T; cin >> D >> R >> T;
  FOR(t, 3, 100) {
    if (Sig(t+D)-6 + Sig(t)-3 == R + T) {
      cout << (R-T - (Sig(t+D)-6) + (Sig(t)-3) ) / 2 << endl;
      return 0;
    }
  }
}
