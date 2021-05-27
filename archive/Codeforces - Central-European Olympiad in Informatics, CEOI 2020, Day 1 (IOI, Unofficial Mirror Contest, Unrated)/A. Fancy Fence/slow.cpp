#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct modInt {
  int MOD;

  modInt(int MOD) { this->MOD = MOD; }

  int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }

  int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }

  int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }

  int pow(int x, ll p) {
    if (p == 0) {
      return 1;
    }
    int t = pow(x, p / 2);
    if ((p & 1) == 1) {
      return mul(mul(t, t), x);
    }
    return mul(t, t);
  }

  int inv(int x) { return pow(x, MOD - 2); }

  int div(int x, int y) { return mul(x, inv(y)); }
} Op(1e9 + 7);

const int N = 1e5 + 5;

int n;
int h[N], w[N];
stack<ii> st;

int cal(int h, int w) {
  int a = Op.mul(h, w);
  int b = Op.mul(a, Op.add(w, h) - 2);
  int c = Op.sub(Op.mul(a, a), Op.add(a, b));
  return Op.add(Op.add(a, Op.div(b, 2)), Op.div(c, 4));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cur = 0;
    while (!st.empty() && st.top().first >= h[i]) {
      ii p = st.top();
      st.pop();
      cur = Op.add(cur, p.second);
      if (p.first > h[i]) {
        if (!st.empty()) {
          ans = Op.add(ans, Op.sub(cal(p.first, cur), cal(max(h[i], st.top().first), cur)));
        } else {
          ans = Op.add(ans, Op.sub(cal(p.first, cur), cal(h[i], cur)));
        }
      }
    }
    st.push({h[i], Op.add(w[i], cur)});
  }
  cout << ans << "\n";
   int cur = 0;
  while (!st.empty()) {
    ii p = st.top();
    st.pop();
    cur = Op.add(cur, p.second);
    if (!st.empty()) {
      ans = Op.add(ans, Op.sub(cal(p.first, cur), cal(st.top().first, cur)));
    } else {
      ans = Op.add(ans, cal(p.first, cur));
    }
  }
  cout << ans << "\n";
}
