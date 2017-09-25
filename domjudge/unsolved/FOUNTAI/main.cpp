
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
#define FOR(i,a,b) for(ll i = (a); i < (b); ++i)
#define all(c) begin(c),end(c)
double eps = 1e-9;
const long double PI = 3.141592653589793238L;

#define MAX_N 200001

void swap(ll& a, ll& b) {
  ll tmp = a;
  a = b;
  b = tmp;
}

bool asc(pll a, pll b) {
  return a.first < b.first;
}
bool desc(pll a, pll b) {
  return a.first > b.first;
}

int main() {
  ll x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;
  bool down = false;
  if (x1 > x2) {
    swap(x1,x2);
    swap(y1,y2);
  } // x1 <= x2
  if (y1 > y2) {
    down = true;
  }
  ll N;
  cin >> N;
  vector<pll> fountains;
  FOR(i,0,N) {
    ll xi,yi;
    cin >> xi >> yi;
    if (xi >= x1 && xi <= x2) {
      if ((down && yi <= y1 && yi >= y2) ||
          (!down && yi >= y1 && yi <= y2)) {
        fountains.push_back(pll(xi,yi));
      }
    }
  }
  if (down) {
    sort(all(fountains), desc);
  } else {
    sort(all(fountains), asc);
  }
  ll n = fountains.size();
  vl A;
  FOR(i,0,n) {
    A.push_back(fountains[i].second);
  }
  ll L[MAX_N];
  ll lis = 0;
  FOR(i,0,n) {
    ll pos = lower_bound(L, L + lis, A[i]) - L;
    L[pos] = A[i];
    if (pos + 1 > lis) {
      lis = pos + 1;
    }
  }

  double manhattan = (abs(x1 - x2) + abs(y1 - y2)) * 100;
  manhattan -= lis * (20.0 - 5.0 * PI);
  if (lis > abs(y1 - y2)) { // TODO: dis is wrong
    manhattan += 20.0 - 5.0*PI;
    manhattan += 10.0*PI - 20.0;
  }
  cout << setprecision(30) << manhattan << endl;
}
