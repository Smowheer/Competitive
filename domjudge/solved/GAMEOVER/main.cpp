
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
ll T,N,W,C,F;
vl w, c, f;
map<vl, ll> pwcf_to_ans;

ll calc(vl pwcf) {
  ll cp=pwcf[0], cw=pwcf[1], cc=pwcf[2], cf=pwcf[3];
  if (cw <= 0 && cc <= 0 && cf <= 0) return 0;
  if (cp >= N) return 1000;
  if (pwcf_to_ans.count(pwcf) == 1) return pwcf_to_ans[pwcf];//still correct if you remove this!
  ll mini = min(1 + calc({cp+1,cw-w[cp],cc-c[cp],cf-f[cp]}), calc({cp+1,cw,cc,cf}));
  pwcf_to_ans[pwcf] = mini;
  return mini;
}

int main() {
  ios::sync_with_stdio(false);
  cin >> T;
  while(T-->0) {
    cin >> N >> W >> C >> F;
    pwcf_to_ans.clear();
    w.resize(N); c.resize(N); f.resize(N);
    FOR(i,0,N) cin >> w[i] >> c[i] >> f[i];
    ll sw=0,sc=0,sf=0;
    FOR(i,0,N) {
      sw+=w[i];sc+=c[i];sf+=f[i];
    }
    if (sw < W || sc < C || sf < F) cout << "game over" << endl;
    else cout << calc({0,W,C,F}) << endl;
  }
}
