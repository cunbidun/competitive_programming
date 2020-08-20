#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;

int n, vis[N];
ll ans, a[N], b[N];
vi g[N];

vi l, e, f;

void topologicalSort(int u) {
  vis[u] = 1;
  for (int v : g[u])
    if (!vis[v]) {
      topologicalSort(v);
    }
  l.push_back(u);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    if (b[i] != -1) {
      g[i].push_back(b[i]);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      topologicalSort(i);
    }
  }
  reverse(all(l));

  for (int i : l) {
    if (a[i] < 0) {
      e.push_back(i);
      ans += a[i];
    } else {
      f.push_back(i);
      ans += a[i];
      a[b[i]] += a[i];
    }
  }

  cout << ans << "\n";
  for (int i : f) {
    cout << i << " ";
  }
  reverse(all(e));
  for (int i : e) {
    cout << i << " ";
  }
  cout << '\n';
}