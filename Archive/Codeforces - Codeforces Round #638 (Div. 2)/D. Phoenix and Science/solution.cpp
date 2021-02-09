#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> l;
    int cur = 1;
    while (cur <= n) {
      l.push_back(cur);
      n -= cur;
      cur *= 2;
    }
    if (n != 0) {
      l.push_back(n);
    }
    sort(l.begin(), l.end());
    cout << l.size() - 1 << "\n";
    for (int i = 1; i < (int)l.size(); i++) {
      cout << l[i] - l[i - 1] << " ";
    }
    cout << "\n";
  }
}
