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

ll ctoll(const char c) {
  return (ll)(c - '0');
}

char lltoc(ll n) {
  return ((char)n) + '0';
}

int main() {
  ios::sync_with_stdio(false);
  ll N; cin >> N;
  while(N-->0) {
    ll sum = 0;
    string num;
    cin >> num;
    ll r = num.size() % 2;
    for (ll i = 0; i < (ll)(num.size()); ++i) {
      ll a = ctoll(num[i]);
      if (i % 2 == r) {
        a *= 2;
        if (a >= 10) {
          a = a/10 + a%10;
        }
      }
      sum += a;
    }
    if (sum % 10 == 0) {
      cout << "PASS" << endl;
    } else {
      cout << "FAIL" << endl;
    }
  }
}
