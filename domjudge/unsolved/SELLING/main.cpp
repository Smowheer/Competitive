
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define all(c) begin(c),end(c)
double eps = 1e-9;

int main() {
  ll c,m;
  cin >> c >> m;
  vll sell(m, vl(c, 0));
  FOR(i,0,m) FOR(j,0,c) cin >> sell[i][j];
  vll dp(m, vl(c+1, 0));
  FOR(i,0,m) dp[i][0] = 0;
  
}
