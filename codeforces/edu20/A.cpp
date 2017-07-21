#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vvi;

int fill(int n, int k) {
  vvi.resize(n);
  for (int i = 0; i < vvi.size(); ++i) {
    vvi[i].assign(n, 0);
  }
  if (k > n * n) {
    cout << "-1" << endl;
    return 0;
  } else {
    int left = k;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (left == 0) return 1;
        if (vvi[i][j] == 1) continue;
        if (i == j) {
          left--;
          vvi[i][j] = 1;
        } else if (left >= 2) {
          left -= 2;
          vvi[i][j] = 1;
          vvi[j][i] = 1;
        }
      }
    }
  }
  return 1;
}

void print_mat(int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << vvi[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  if (fill(n, k)) {
    print_mat(n);
  }


  return 0;
}
