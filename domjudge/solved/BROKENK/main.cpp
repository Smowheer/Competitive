#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define all(c) begin(c),end(c)

vl table;
set<char> cur;
ll l,r,m,len,best;
string s;

void iterate_r() {
  while (cur.size() < m+1 && r < len+1) {
    cur.insert(s[r]);
    table[s[r]] = r;
    ++r;
  }
  cur.erase(s[r-1]);
  --r;
}

void iterate_l() {
  while (cur.size() >= m && l < len) {
    if (l == table[s[l]]) {
      cur.erase(s[l]);
    }
    ++l;
  }
}

int main() {
  while (true) {
    cur.clear();
    getline(cin, s);
    m = stoi(s);
    if (m == 0) break;
    getline(cin, s);
    l = 0;
    r = 0;
    table.assign(400, -1);
    len = s.size();
    best = 0;
    while (r < len) {
      iterate_r();
      best = max(best, r - l);
      iterate_l();
    }
    cout << best << endl;
  }
}
