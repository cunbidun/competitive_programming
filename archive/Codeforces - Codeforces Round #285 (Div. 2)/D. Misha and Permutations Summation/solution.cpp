#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;

struct fenwick_tree {
  vi bit;
  int n;

  fenwick_tree() {
    this->n = N - 1;
    bit.assign(N - 1, 0);
  }

  void update(int p, int val) {
    if (p == 0) {
      return;
    }
    while (p <= n) {
      bit[p] += val;
      p += (p & (-p));
    }
  }

  int get(int p) {
    int res = 0;
    while (p >= 1) {
      res += bit[p];
      p -= p & -p;
    }
    return res;
  }

  int get(int l, int r) { return get(r) - get(l - 1); }
} tp, tq, ta;

int n, a[N], p[N], q[N], mp[N], mq[N], cp[N], cq[N], ch[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> q[i];
  }

  mp[n + 1] = N;
  for (int i = n; i >= 1; i--) {
    mp[i] = min(mp[i + 1], p[i]);
  }
  for (int i = 1; i <= n; i++) {
    cp[i] = p[i] - mp[i] - tp.get(mp[i], p[i] - 1);
    tp.update(p[i], 1);
  }

  mq[n + 1] = N;
  for (int i = n; i >= 1; i--) {
    mq[i] = min(mq[i + 1], q[i]);
  }
  for (int i = 1; i <= n; i++) {
    cq[i] = q[i] - mq[i] - tq.get(mq[i], q[i] - 1);
    tq.update(q[i], 1);
  }

  for (int i = 1; i <= n; i++) {
    a[i] = cq[i] + cp[i];
  }
  for (int i = n; i >= 1; i--) {
    a[i - 1] += a[i] / (n - i + 1);
    a[i] %= (n - i + 1);
  }

  int mn = 0;
  for (int i = 1; i <= n; i++) {
    int l = mn + a[i], r = n;
    while (l < r) {
      int m = (l + r) / 2;
      if (m - mn + 1 - ta.get(mn, m) >= a[i] + 1) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    int cur = r;
    cout << cur << " ";
    ch[cur] = 1;
    ta.update(cur, 1);
    while (ch[mn]) {
      mn++;
    }
  }
  cout << "\n";
  assert(mn == n);
}