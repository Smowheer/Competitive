
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
ll N, Q;
vl arr;
vl pre;
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  FOR(i,0,N) {
    ll tmp; cin >> tmp;
    arr.push_back((ll)(tmp % 4 == 0));
  }
  ll csum = 0;
  FOR(i,0,N) {
    csum += arr[i];
    pre.push_back(csum);
  }
  cin >> Q;
  FOR(i,0,Q) {
    ll dum,a,b; cin >> dum >> a >> b;
    cout << pre[b] - pre[a] + arr[a] << endl;
  }
}
