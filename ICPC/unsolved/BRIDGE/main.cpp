#include <bits/stdc++.h>
typedef long long ll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

using namespace std;

ll n, b;
vector<ll> t;
vector<ll> w;
ll state;
vector<ll> memo;

int main() {
  cin >> n >> b;
  FOR(i, 0, n) {
    ll ti;
    cin >> ti;
    t.push_back(ti);
  }
  FOR(i, 0, n) {
    ll wi;
    cin >> wi;
    w.push_back(wi);
  }
  state = 0;
  memo.assign(1 << (n+1), -1);
  dp(0, 0);
  if (memo[0] == -1

}

void dp(ll state, ll time) {
  if (memo[state] != -1) {
  }
  if (state == 1
  min_time = 1000000;
  vector<pair<ll, ll>> state_time = next_states(state);
  for (pair<ll, ll> s_t : state_time) {
    if (dp(s_t.first, time + s_t.second) <= min_time) {
      min_time = dp(s_t.first, time + s_t.second);
    }
  }
  return time + min_time;
}


vector<pair<ll, ll>> next_states(ll state) {
  return 0;
}
