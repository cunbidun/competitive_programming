#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define left first.second
#define right first.right

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
const int MOD = 998244353;

int a[N], s[N], n, q;
set<pair<ii, int>> st;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  a[1] = 1;
  s[1] = 1;
  for (int i = 2; i <= n; i++) {
    a[i] = (a[i - 1] * 10) % MOD;
    s[i] = (s[i - 1] + a[i]) % MOD;
  }
  int ans = s[n];
  cout << ans << "\n";
  while (q--) {
    int l, r, v;
    cin >> l >> r >> v;
    ans += 1LL * (s[r] - s[l - 1]) * v;
    st.insert({{r, l}, v});
    cout << ans << "\n";
  }
}