#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> v3l;
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define all(c) begin(c),end(c)

ll N,K;
vl seq;
vl pre;

v3l dp;
v3l dpx;
v3l dpy;
vl xs;

ll calc(int i, int j, int k) {
  if (dp[i][j][k] != -1) return dp[i][j][k];
  ll maxx = -1;
  ll mx = -1;
  ll my = -1;
  FOR(x,i,j) {
    ll facx = (pre[x] - pre[i] + seq[i]) * (pre[j] - pre[x+1] + seq[x+1]);
    FOR(y,0,k) {
      ll d = facx + calc(i,x,y) + calc(x+1,j,k-1-y);
      if (d >= maxx) {
        maxx = d;
        mx = x;
        my = y;
      }
    }
  }
  dp[i][j][k] = maxx;
  dpx[i][j][k] = mx;
  dpy[i][j][k] = my;
  return maxx;
}

void reconstruct(int i, int j, int k) {
  if (k <= 0) return;
  ll mx = dpx[i][j][k];
  ll my = dpy[i][j][k];
  xs.push_back(mx+1);
  reconstruct(i, mx, my);
  reconstruct(mx+1, j, k-1-my);
}

int main() {
  cin >> N >> K;
  seq.resize(N);
  pre.resize(N);
  ll sum = 0;
  FOR(i,0,N) {
    cin >> seq[i];
    sum += seq[i];
    pre[i] = sum; // sum(i to j) = pre[j] - pre[i] + seq[i]
  }
  dp.assign(N, vvl(N, vl(K+1, -1)));
  dpx.assign(N, vvl(N, vl(K+1, -1)));
  dpy.assign(N, vvl(N, vl(K+1, -1)));
  FOR(i,0,N) {
    FOR(j,0,N) {
      dp[i][j][0] = 0;
      if (i == j) {
        FOR(k,0,K+1) {
          dp[i][j][k] = 0;
        }
      }
    }
  }
  cout << calc(0,N-1,K) << endl;
  reconstruct(0,N-1,K);
  sort(all(xs));
  cout << xs[0];
  FOR(i,1,xs.size()) {
    cout << " " << xs[i];
  } cout << endl;

  //FOR(i,0,N) FOR(j,0,N) FOR(k,0,K+1) cout << i << "," << j << "," << k << ":" << dpx[i][j][k] << "," << dpy[i][j][k] << endl;
}
