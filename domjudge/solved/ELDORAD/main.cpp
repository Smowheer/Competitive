
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
  while (true) {
    ll n,k;
    cin >> n >> k;
    if (n == 0 && k == 0) break;
    vl seq; seq.resize(n+1);
    FOR(i,1,n+1) {
      cin >> seq[i];
    }
    vvl dp(n+1, vl(k+1,0));
    FOR(i,1,n+1) {
      dp[i][1] = 1;
    }
    FOR(i,1,n+1) {
      FOR(j,1,i) {
        if (seq[i] > seq[j]) {
          FOR(p,2,k+1) {
            dp[i][p] += dp[j][p-1];
          }
        }
      }
    }
    ll ans = 0;
    FOR(i,1,n+1) ans += dp[i][k];
    cout << ans << endl;
  }
}
