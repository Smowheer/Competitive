#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll n;
  cin >> n; 
  vector<ll> nums;
  nums.resize(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> nums[i];
  }
  int pl = 1;
  int pr = -1;
  int ml = 1;
  int mr = -1;
  int p_max = 0;
  int m_max = 0;
  int p_sum = 0;
  int m_sum = 0;
  for (int i = 1; i < n; ++i) {
    ll tmp = abs(nums[i] - nums[i+1]);
    if (i % 2 == 0) {
      p_sum -= tmp;
    } else {
      p_sum += tmp;
      if (p_sum > p_max) {
        p_max = p_sum;
      }
    }
  }
  for (int i = 2; i < n; ++i) {
    ll tmp = abs(nums[i] - nums[i+1]);
    if (i % 2 == 0) {
      m_sum += tmp;
    } else {
      m_sum -= tmp;
    }
  }
  return 0;
}
