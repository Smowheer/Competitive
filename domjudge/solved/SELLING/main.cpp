
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define all(c) begin(c),end(c)
double eps = 1e-9;
const ll oo = 0x3f3f3f3f3f3f3f3f;

ll M, C;
vvl sell;
vvl dp;

ll camax(ll m, ll c) {
  if (m >= M) {
    return 0;
  }
  if (c == 0) {
    return 0;
  }
  if (dp[m][c] != -1) return dp[m][c];
  ll maxi = 0;
  FOR(i, 0, c+1) {
    maxi = max(sell[m][i] + camax(m+1, c-i), maxi);
  }
  dp[m][c] = maxi;
  return maxi;
}

int main() {
  cin >> C >> M;
  sell = vvl(M, vl(C+1, 0));
  FOR(i,0,M) FOR(j,1,C+1) cin >> sell[i][j];
  dp = vvl(M, vl(C+1, -1));
  cout << camax(0, C) << endl;
}
