
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
#define TR(X) ({ if(0) cerr << "TR: " << (#X) << " = " << (X) << endl;})
ll N;
double L,W;
vector<double> drops;
vector<double> place;
vector<vector<double>> dp;
double calc(ll i, ll j) {
  TR(i);
  TR(j);
  if (i == N/2 && j == N/2) return 0.0;
  if (dp[i][j] >= 0.0) return dp[i][j];
  ll k = i + j;
  double mini = 1e20;
  if (i < N/2) mini = min(mini, hypot(W, abs(drops[k]-place[i])) + calc(i+1,j));
  if (j < N/2) mini = min(mini, hypot(0, abs(drops[k]-place[j])) + calc(i,j+1));
  dp[i][j] = mini;
  return mini;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> N;
  drops.resize(N);
  cin >> L >> W;
  FOR(i,0,N) cin >> drops[i];
  sort(all(drops));
  dp = vector<vector<double>>(N/2+1, vector<double>(N/2+1, -1.));
  double h = L / (N/2-1);
  FOR(i,0,N/2) place.push_back(0.0 + i * h);
  FOR(i,0,sz(place)) TR(place[i]);
  cout << setprecision(20) << calc(0,0) << endl;
}
