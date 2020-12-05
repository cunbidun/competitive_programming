#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

void solve() {
  ll k;
  cin >> k;
  if (k % 2 == 1) {
    cout << -1 << "\n";
    return;
  }
  vi ans;
  ans.push_back(1);
  k -= 2;
  while (k > 0) {
    ll cur = 2;
    while (cur * 2 <= k) {
      ans.push_back(0);
      cur *= 2;
      k -= cur;
    }
    if (k == 0) {
      break;
    }
    k -= 2;
    ans.push_back(1);
  }
  cout << sz(ans) << "\n";
  for (int i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}