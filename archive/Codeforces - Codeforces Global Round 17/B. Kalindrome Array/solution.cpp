#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    int l = 0, r = N - 1;
    while (l <= r) {
      if (a[l] != a[r]) {
        break;
      }
      l++;
      r--;
    }
    if (l > r) {
      cout << "YES\n";
      continue;
    }
    auto check = [&](int l) -> bool {
      vector<int> tmp;
      for (int i = 0; i < N; i++) {
        if (a[i] != a[l]) {
          tmp.push_back(a[i]);
        }
      }
      vector<int> r = tmp;
      reverse(r.begin(), r.end());
      return tmp == r;
    };
    if (!check(l) && !check(r)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
