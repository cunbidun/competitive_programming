#include <bits/stdc++.h>

using namespace std;

// Code below this line will be copied.

#define X first
#define Y second
#define PB push_back
#define MP make_pair
#define scd(a) scanf("%d", &a)
#define scdd(a, b) scanf("%d%d", &a, &b)
#define scddd(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define ALL(x) x.begin(), x.end()
#define sz(a) ((int)a.size())
#define getmid ((l + r) >> 1)
#define mst(var, val) memset(var, val, sizeof(var))
#define IOS                    \
  ios::sync_with_stdio(false); \
  cin.tie(0)
#define lowbit(x) x &(-x)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)
#define ls rt << 1
#define rs rt << 1 | 1
using namespace std;
#ifdef local
#define dbg(args...) cout << #args << " -> ", err(args);
void err() {
  cout << endl;
}
template <typename T, typename... Args>
void err(T a, Args... args) {
  cout << a << ' ';
  err(args...);
}
#else
#define dbg(args...)
#endif // local

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<double, double> pdd;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const long double eps = 1e-8;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
const int N = 2e5 + 100;
const int M = (1 << 20) + 10;

template <class T>
inline void read(T &x) {
  x = 0;
  char c = getchar();
  bool f = 0;
  for (; !isdigit(c); c = getchar()) {
    f ^= c == '-';
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + (c ^ 48);
  }
  x = f ? -x : x;
}

template <class T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  T y = 1;
  int len = 1;
  for (; y <= x / 10; y *= 10) {
    ++len;
  }
  for (; len; --len, x %= y, y /= 10) {
    putchar(x / y + 48);
  }
}
ll qpow(ll a, ll b, ll mod) {
  ll ans = 1;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % mod;
    }
    b >>= 1;
    a = (a * a) % mod;
  }
  return ans;
}

vector<int> g[N];
int n;
int dep[N];
int ans;
void dfs(int u, int fa) {
  if (g[u].size() == 1 && u != 1) {
    dep[u] = 0;
    return;
  }
  dep[u] = inf;
  for (int v : g[u]) {
    if (v == fa) {
      continue;
    }
    dfs(v, u);
    dep[u] = min(dep[v] + 1, dep[u]);
  }
}
void dfs1(int u, int fa) {
  vector<int> tmp;
  if (g[u].size() == 1 && u != 1) {
    return;
  }
  for (int v : g[u]) {
    if (v == fa) {
      continue;
    }
    dfs1(v, u);
    tmp.PB(dep[v]);
  }
  sort(ALL(tmp));
  int sz = tmp.size();
  if (u == 1) {
    ans = max(ans, tmp[sz - 1] + 1);
    if (sz > 1) {
      ans = max(ans, tmp[sz - 2] + 2);
    }
    return;
  }
  if (sz == 1) {
    ans = max(ans, tmp[sz - 1] + 1);
  } else {
    ans = max(ans, tmp[sz - 2] + 2);
    ans = max(ans, tmp[sz - 1] + 2);
  }
}
int main() {
#ifdef local
  freopen("in.txt", "r", stdin);
#endif // local
  IOS;
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    rep1(i, n) g[i].clear();
    for (int i = 1; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      g[x].PB(y);
      g[y].PB(x);
    }
    dfs(1, 0);
    ans = 0;
    dfs1(1, 0);
    cout << ans << "\n";
  }
  return 0;
}
