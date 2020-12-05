#include <bits/stdc++.h>

using namespace std;

// Code below this line will be copied.

const int N = 1e5 + 5;
int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (s.find(m - x) != s.end()) {
      cout << "YES\n";
      return 0;
    }
    s.insert(x);
  }
  cout << "NO\n";
  return 0;
}