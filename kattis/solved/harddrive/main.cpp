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
using vd = vector<double>;
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

// idea
// separate in first block and subsequent blocks between two '0'
// use greedy
// TODO
// 5 2 3
// 2 3 5
// *00*0
// call(4,4) call(3,2) call(1)
//
// 7 4 2
// 2 7
// *0****0
// call(3,6) call(1)
//
// 8 5 4
// 2 4 5 8
// *0*00**0
// call(6,7) call(5,4) call(3,3) call(1)
//
// 16 7 4
// 3 7 12 16
// **0***0****0***0
// call(13,15) call(8,11) call(4,6) call(2)
//
// 5 4 1
// 5
// ****0
// call(4)
//
// 4 3 1
// 4
// ***0
// call(3)
vector<ll> bits;
vector<ll> broken;
ll N = 0;
ll C = 0;
ll B = 0;

void fill_bits(ll from, ll to) {
  if (from > to) return;
  if (C <= 1) return;
  for (ll i = to; i >= from; i-=2) {
    bits[i] = 1;
    C -= 2;
    if (C <= 1) return;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin >> N >> C >> B;
  bits.assign(N+1, 0);
  broken.resize(B);
  FOR(i, 0, B) { cin >> broken[i]; }
  for (ll i = broken.size()-1; i >= 1; --i) {
    fill_bits(broken[i-1]+1, broken[i]-1);
  }
  fill_bits(1, broken[0]-1);
  if (C == 1) bits[1] = 1;

  FOR(i, 1, N+1) {
    cout << bits[i];
  }
  cout << endl;

}
