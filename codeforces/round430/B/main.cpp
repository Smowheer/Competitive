#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

struct point { 
  double x, y;
  point() {x = y = 0;}
  point(double _x, double _y) : x(_x), y(_y) {}
};

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

int main() {
  double r,d; 
  cin >> r >> d;
  int n;
  cin >> n;
  point orig(0,0);
  ll c = 0;
  FOR(i,0,n) {
    double xi,yi,ri;
    cin >> xi >> yi >> ri;
    point target(xi,yi);
    if (dist(target, orig) + ri <= r && dist(target, orig) - ri >= r-d) {
      c++;
    }
  }
  cout << c << endl;
}
