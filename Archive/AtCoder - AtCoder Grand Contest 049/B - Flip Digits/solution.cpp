#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n;
string S, T;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  cin >> S >> T;
  S = "1" + S + "1";
  T = "1" + T + "1";
  int pt = 0;
  int ps = 0;
  int cnt = 0;
  ll ans = 0;
  stack<int> p1;
  while (pt <= n + 1) {
    while (T[pt] != '1') {
      pt++;
    }
    while (ps < pt) {
      if (S[ps] == '1') {
        if (!p1.empty()) {
          ans += ps - p1.top();
          p1.pop();
          cnt--;
        } else {
          p1.push(ps);
          cnt++;
        }
      }
      ps++;
    }
    while (cnt > 0) {
      if (S[ps] == '1') {
        if (p1.empty()) {
          cout << -1 << "\n";
          return 0;
        }
        ans += ps - p1.top();
        p1.pop();
        cnt--;
      }
      ps++;
      if (ps > n + 1) {
        cout << -1 << "\n";
        return 0;
      }
    }
    assert(cnt == 0);

    while (S[ps] != '1') {
      ps++;
    }
    if (pt != n + 1 && ps > n) {
      cout << -1 << "\n";
      return 0;
    }
    ans += ps - pt;
    pt++;
    ps++;
  }
  cout << ans << "\n";
}