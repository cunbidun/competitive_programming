#include <bits/stdc++.h>

using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<array<int, 2>> a;
  a.push_back({1, 2});
  for (auto [f, s] : a) {
    cout << f << ' ' << s << '\n';
  }
  cout << a[1][1] << '\n';
}
