#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
const int INF = 1e9 + 5;

int n, a[N], f[N], l[N], g[N];
stack<ii> s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    f[i] = N;
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    while (!s.empty()) {
      if (s.top().first >= a[i]) {
        s.pop();
      } else {
        break;
      }
    }
    if (s.empty()) {
      l[i] = -1;
    } else {
      l[i] = s.top().second;
    }
    s.push({a[i], i});
  }
  while (!s.empty()) {
    s.pop();
  }
  for (int i = 1; i <= n; i++) {
    while (!s.empty()) {
      if (s.top().first <= a[i]) {
        s.pop();
      } else {
        break;
      }
    }
    if (s.empty()) {
      g[i] = -1;
    } else {
      g[i] = s.top().second;
    }
    s.push({a[i], i});
  }
  f[1] = 0;
  for (int i = 2; i <= n; i++) {
    f[i] = min(f[i], f[i - 1] + 1);
    if (a[i - 1] > a[i]) {
      int cur = l[i - 1];
      while (cur != -1) {
        f[i] = min(f[i], f[cur] + 1);
        if (a[cur] <= a[i]) {
          break;
        }
        cur = l[cur];
      }
    }
    if (a[i - 1] < a[i]) {
      int cur = g[i - 1];
      while (cur != -1) {
        f[i] = min(f[i], f[cur] + 1);
        if (a[cur] >= a[i]) {
          break;
        }
        cur = g[cur];
      }
    }
  }
  cout << f[n] << "\n";
}