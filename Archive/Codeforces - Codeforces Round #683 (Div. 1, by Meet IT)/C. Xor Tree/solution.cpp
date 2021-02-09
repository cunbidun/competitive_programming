#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> a, int n) {
  if (n == -1) {
    return 1;
  }
  vector<int> v0, v1;
  for (int p : a) {
    if (((p >> n) & 1) == 0) {
      v0.push_back(p);
    } else {
      v1.push_back(p);
    }
  }
  if (v0.size() == 0) {
    return solve(v1, n - 1);
  }
  if (v1.size() == 0) {
    return solve(v0, n - 1);
  }
  return max(solve(v0, n - 1), solve(v1, n - 1)) + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &p : a) {
    cin >> p;
  }
  cout << n - solve(a, 30) << "\n";
}
