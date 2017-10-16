#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
typedef vector<ll> vl;
ll N;
int main() {
  cin >> N;
  while (N-->0) {
    ll k; cin >> k;
    vl left(k,0), right(k,0);
    map<ll,ll> lmap;
    FOR(i,0,k) cin >> left[i];
    FOR(i,0,k) cin >> right[i];
    ll minn = 0;
    FOR(i,0,k) {
      if (lmap.count(left[i]) == 0) lmap[left[i]] = 1;
      else lmap[left[i]]++;
    }
    FOR(i,0,k) {
      if (lmap.count(right[i]) == 1 && lmap[right[i]] > 0) {
        lmap[right[i]]--;
      }
      minn += right[i];
    }
    for (auto a : lmap) {
      minn += a.first * a.second;
    }
    ll maxx = 0;
    FOR(i,0,k) {
      ll sumi = 0;
      FOR(j,0,k) {
        sumi += min(left[i], right[j]);
      }
      maxx += sumi;
    }
    printf("Minimalni budova obsahuje %lld kostek, maximalni %lld kostek.\n", minn, maxx);
  }
}
