// 7c45a57acf6288e3b86595e46c7637f96880975ab86a72ff2640f38e06b01b49
#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int cnt[5005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
    mx = max(x, mx);
  }
  int ans = 1;
  vi l1, l2;
  for (int i = 1; i < mx; i++) {
    if (cnt[i] == 0) {
      continue;
    }
    ans += min(2, cnt[i]);
    l1.push_back(i);
    if (cnt[i] >= 2) {
      l2.push_back(i);
    }
  }
  cout << ans << "\n";
  for (int i : l1) {
    cout << i << " ";
  }
  cout << mx << " ";
  reverse(all(l2));
  for (int i : l2) {
    cout << i << " ";
  }
  cout << "\n";
}