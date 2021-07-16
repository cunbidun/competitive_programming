#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  auto ask = [](int a, int b) -> int {
    cout << "? " << a << ' ' << b << endl;
    string r;
    cin >> r;
    return (r[0] == 'Y') ? 1 : 0;
  };
  int N;
  cin >> N;
  vector<array<int, 2>> a;
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    x = N - 1 - x;
    a.push_back({x, i});
  }
  sort(a.begin(), a.end());
  struct pair {
    array<int, 2> f, s;
    int diff;
  };
  vector<pair> l;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      l.push_back({a[i], a[j], abs(a[i][0] - a[j][0])});
    }
  }
  sort(l.begin(), l.end(), [](auto A, auto B) {
    return A.diff > B.diff;
  });
  for (auto p : l) {
    if (ask(p.f[1], p.s[1])) {
      cout << "! " << p.f[1] << ' ' << p.s[1] << endl;
      return 0;
    }
  }
  cout << "! 0 0" << endl;
}
