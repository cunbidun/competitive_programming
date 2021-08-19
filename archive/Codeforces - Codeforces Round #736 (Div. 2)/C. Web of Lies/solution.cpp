#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<set<int>> a(N + 1);
  set<int> l;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    a[u].insert(v);
    a[v].insert(u);
  }
  for (int i = 1; i <= N; i++) {
    auto it = a[i].rbegin();
    if (it != a[i].rend() && *it > i) {
      l.insert(i);
    }
  }
  int Q;
  cin >> Q;
  while (Q--) {
    int t;
    cin >> t;
    if (t == 3) {
      cout << N - (int)l.size() << '\n';
    } else {
      int u, v;
      cin >> u >> v;
      if (t == 1) {
        a[u].insert(v);
        a[v].insert(u);
        auto it = a[u].rbegin();
        if (it != a[u].rend() && *it > u) {
          l.insert(u);
        }
        it = a[v].rbegin();
        if (it != a[v].rend() && *it > v) {
          l.insert(v);
        }
      } else {
        a[u].erase(v);
        a[v].erase(u);
        auto it = a[u].rbegin();
        if (it == a[u].rend() || *it < u) {
          l.erase(u);
        }
        it = a[v].rbegin();
        if (it == a[v].rend() || *it < v) {
          l.erase(v);
        }
      }
    }
  }
}
