#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> v1;
  vector<int> v0;
  for (int i = 0; i < n; i++) {
    char x;
    cin >> x;
    if (x == '0') {
      v0.push_back(i);
    } else {
      v1.push_back(i);
    }
  }
  if (k == n || v0.empty() || v1.empty()) {
    cout << "tokitsukaze\n";
    return 0;
  }
  int f0 = v0[0];
  int l0 = v0[v0.size() - 1];
  int f1 = v1[0];
  int l1 = v1[v1.size() - 1];
  if (min(l0 - f0 + 1, l1 - f1 + 1) <= k) {
    cout << "tokitsukaze\n";
    return 0;
  }
  // change all to 0
  for (int i = 0; i < n - k + 1; i++) {
    int nf0 = min(f0, i);
    int nl0 = max(l0, i + k - 1);
    int nf1 = f1;
    if (f1 >= i) {
      nf1 = *upper_bound(v1.begin(), v1.end(), i + k - 1);
    }
    int nl1 = l1;
    if (l1 <= i + k - 1) {
      auto it = lower_bound(v1.begin(), v1.end(), i);
      it--;
      nl1 = *it;
    }
    if (min(nl0 - nf0 + 1, nl1 - nf1 + 1) > k) {
      cout << "once again\n";
      return 0;
    }
  }

  // change all to 1
  for (int i = 0; i < n - k + 1; i++) {
    int nf1 = min(f1, i);
    int nl1 = max(l1, i + k - 1);
    int nf0 = f0;
    if (f0 >= i) {
      nf0 = *upper_bound(v0.begin(), v0.end(), i + k - 1);
    }
    int nl0 = l0;
    if (l0 <= i + k - 1) {
      auto it = lower_bound(v0.begin(), v0.end(), i);
      it--;
      nl0 = *it;
    }
    if (min(nl0 - nf0 + 1, nl1 - nf1 + 1) > k) {
      cout << "once again\n";
      return 0;
    }
  }
  cout << "quailty\n";
}
