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

int main() {
  ios::sync_with_stdio(false);
  vector<string> field;
  FOR(i,0,8) {
    string line; cin >> line;
    field.push_back(line);
  }
  ll count = 0;
  FOR(i,0,8) {
    FOR(j,0,8) {
      if (field[i][j] == '*') count++;
    }
  }
  if (count != 8) {
    cout << "invalid" << endl;
    return 0;
  }

  ll di[] = {-1, 0, 1,-1, 1,-1, 0, 1};
  ll dj[] = {-1,-1,-1, 0, 0, 1, 1, 1};
  FOR(i,0,8) {
    FOR(j,0,8) {
      if (field[i][j] == '*') {
        FOR(k, 0, 8) {
          FOR(r, 1, 8) {
            ll ni = i + r*di[k];
            ll nj = j + r*dj[k];
            if (ni < 0 || nj < 0 || ni > 7 || nj > 7) continue;
            if (field[ni][nj] == '*') {
              cout << "invalid" << endl;
              return 0;
            }
          }
        }
      }
    }
  }
  cout << "valid" << endl;
}
