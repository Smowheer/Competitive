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

ll who(ll p1, ll p2) {
  if (p1 > p2) return -1;
  else return 1;
}

ll game_result(ll current, string game) {
  stringstream ss(game);
  ll p1, p2;
  ss >> p1;
  ss.ignore();
  ss >> p2;
  if (p1 == p2) return 0;
  if (max(p1, p2) < 6) return 0;

  if (current == 3) {
    if (abs(p1 - p2) < 2) return 0;
    return who(p1, p2);
  } else {
    if (max(p1, p2) >= 8) return 0;
    // special case 7:6 6:7
    if (p1 == 7 || p2 == 7) {
      if (abs(p1 - p2) > 2) return 0;
      return who(p1, p2);
    } else {
      if (abs(p1 - p2) < 2) return 0;
      return who(p1, p2);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  string p1, p2; cin >> p1 >> p2;
  ll N; cin >> N;
  ll federer = 0;
  if (p1 == "federer") {
    federer = -1;
  } else if (p2 == "federer") {
    federer = 1;
  }
  getline(cin, p1);
  while(N-->0) {
    string results;
    getline(cin, results);
    stringstream str(results);
    string game;
    ll current = 0;
    bool valid = true;
    ll winner = 0;
    while (getline(str, game, ' ')) {
      if (abs(winner) >= 2) valid = false;
      current++;
      ll res = game_result(current, game);
      if (res == 0) valid = false;
      if (federer != 0 && res != federer) valid = false;
      winner += res;
    }
    if (abs(winner) < 1) valid = false;
    if (current > 3 || current < 2) valid = false;
    if (valid) cout << "da";
    else cout << "ne";
    cout << endl;
  }
}
