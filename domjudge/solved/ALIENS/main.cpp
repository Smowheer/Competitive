
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> v3l;
typedef pair<ll, ll> pll;
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define all(c) begin(c),end(c)
#define INF 0x3f3f3f3f3f3f3f3f
#define TR(X) ({ if(0) cerr << "TR: " << (#X) << " = " << (X) << endl;})
double eps = 1e-9;

vvl adj;
vector<bool> vis;
ll N;
vector<pll> edges;
ll S;
bool found;

bool dfs(ll cur, ll t) {
  if (cur == t) found = true;
  vis[cur] = true;
  FOR(i, 0, (ll)adj[cur].size()) {
    ll n = adj[cur][i];
    if (cur == S && n == t) continue;
    if (vis[n]) continue;
    dfs(n, t);
  }
  return false;
}

int main() {
  cin >> N;
  while (N-->0) {
    ll l,k; // l links, k aliens
    cin >> l >> k;
    adj.clear();
    edges.clear();
    adj.resize(k);
    FOR(i,0,l) {
      ll le,ri;
      cin >> le >> ri;
      edges.push_back(pll(le,ri));
      adj[ri].push_back(le); //reverse edges
    }
    FOR(i,0,l) {
      ll le,ri;
      le = edges[i].first;
      ri = edges[i].second;
      TR(le);
      TR(ri);
      S = ri;
      vis.assign(k, false);
      found = false;
      dfs(ri, le);
      if (!found) cout << le << " " << ri << endl;
    }
    if (N) cout << "\n";
  }
}
