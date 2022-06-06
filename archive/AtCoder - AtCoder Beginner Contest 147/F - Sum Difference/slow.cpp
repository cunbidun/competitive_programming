#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int N, X, D;
  cin >> N >> X >> D;
  vector<int> a;
  a.push_back(X);
  int sum = X;
  for (int i = 1; i < N; i++) {
    X += D;
    a.push_back(X);
    sum += X;
  }
  set<int> ans;
  for (int mask = 0; mask < (1 << N); mask++) {
    int S = 0;
    for (int i = 0; i < N; i++) {
      if ((mask >> i) & 1) {
        S += a[i];
      }
    }
    int T = sum - S;
    ans.insert(S - T);
  }
  cout << ans.size() << '\n';
  // for (int i : ans) {
  //   cout << i << ' ';
  // }
  // cout << '\n';
}
