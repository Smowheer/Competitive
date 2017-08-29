#include <bits/stdc++.h>
typedef long long ll;
typedef vector<ll> vll;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;

ll n, b;
vll t, w;

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
}

// dijkstra
