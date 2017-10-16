
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef pair<int,int> ii;
double eps = 1e-9;

#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)

bool near(double a, ll b) {
  return abs(a-b) < eps;
}

int main() {
  ll l,r,x,y;
  double k;
  cin >> l >> r >> x >> y >> k;
  FOR(i,l,r+1) {
    double tmp = i / k;
    if (tmp >= x && tmp <= y && near(tmp, round(tmp))) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}
