#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e3 + 5;
int n, a[N], cnt[1000005];

void clean() {
  for (int i = 1; i <= 2 * n; i++) {
    if (cnt[a[i]] > 0) {
      cnt[a[i]]--;
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + 2 * n);
  for (int i = 1; i < 2 * n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      cnt[a[j]]++;
    }
    vector<ii> ans;
    ans.push_back({a[2 * n], a[i]});
    cnt[a[2 * n]]--;
    cnt[a[i]]--;
    int last = a[2 * n];
    int f = 0;
    for (int j = 2 * n - 1; j >= 1; j--) {
      if (cnt[a[j]] > 0) {
        cnt[a[j]] --;
        if (cnt[last - a[j]] == 0) {
          f = 1;
          break;
        } else {
          cnt[last - a[j]]--;
          ans.push_back({a[j], last - a[j]});
          last = a[j];
        }
      }
    }
    if (!f) {
      cout << "YES\n";
      cout << a[n * 2] + a[i] << "\n";
      for (auto [f, s] : ans) {
        cout << f << " " << s << "\n";
      }
      clean();
      return;
    }
    clean();
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
