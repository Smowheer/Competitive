#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  double a,b;
  int c, len;
  cin >> a >> b >> c >> len;
  vector<char> genes(len);
  for (int i = 0; i < len; ++i) {
    double tmp;
    cin >> tmp;
    if (tmp < a) genes[i] = 'a';
    else if (tmp > b) genes[i] = 'b';
    else genes[i] = 'X';
  }
  int last_a = -1;
  int last_b = -1;
  int a_count = 0;
  int b_count = 0;
  vector<pair<int,int>> solutions;
  for (int i = 0; i < len; ++i) {
    if (genes[i] == 'X') continue;
    // A CASE
    else if (genes[i] == 'a') {
      if (last_b != -1) a_count++;
      if (last_a == -1) {
        last_a = i;
      } else {
        if (b_count >= c) { // found a solution
          solutions.push_back(make_pair(last_a, i));
        }
        b_count = 0;
        last_a = i;
      }
    // B CASE
    } else {
      if (last_a != -1) b_count++;
      if (last_b == -1) {
        last_b = i;
      } else {
        if (a_count >= c) { // found a solution
          solutions.push_back(make_pair(last_b, i));
        }
        a_count = 0;
        last_b = i;
      }
    }
  }
  // baXXXXXXXXXabab
  // write solutions
  for (int i = 0; i < (int)solutions.size(); ++i) {
    int from = get<0>(solutions[i]);
    int to = get<1>(solutions[i]);
    for (int j = from; j <= to; ++j) {
      cout << genes[j];
    }
    cout << endl;
  }
  return 0;
}
