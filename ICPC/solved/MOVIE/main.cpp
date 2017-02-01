#include <bits/stdc++.h>

using namespace std;

int main() {
  double L, s;
  int n;
  cin >> L >> s >> n;
  double last = 0.0, fac = 1.0;
  double res = 0.0;
  for (int i = 0; i < n; ++i) {
    double current;
    cin >> current;
    res += (current - last)/fac;
    fac *= s;
    last = current;
  }
  res += (L - last)/fac;
  cout << setprecision(20) << res << endl;

  return 0;
}
