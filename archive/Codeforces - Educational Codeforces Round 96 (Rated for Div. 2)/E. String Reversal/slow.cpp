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

  void _update(int p, int v) {
    while (p <= n) {
      bit[p] += v;
      p += p & -p;
    }
  }

  void update(int l, int r) {
    if (l > r) {
      return;
    }
    _update(l, 1);
    _update(r + 1, -1);
  }

  int get(int p) {
    int res = 0;
    while (p >= 1) {
      res += bit[p];
      p -= p & -p;
    }
    return res;
  }
} t;

queue<int> q[30];
int n;
string s;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  cin >> s;
  s = "*" + s;
  for (int i = 1; i <= n; i++) {
    q[s[i] - 'a'].push(i);
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    char c = s[n - i + 1];
    int p = q[c - 'a'].front();
    int r = p + t.get(p);
    q[c - 'a'].pop();
    ans += r - i;
    t.update(1, p);
  }
  cout << ans << "\n";
}
