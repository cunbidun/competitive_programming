#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k, x, y;
  cin >> n >> k;
  cin >> x >> y;
  set<ii> s;
  for (int i = 1; i <= k; i++) {
    int a, b;
    cin >> a >> b;
    s.insert({a, b});
  }
  int ans = 0;
  for (int i = x + 1; i <= n; i++) {
    if (s.find({i, y}) == s.end()) {
      ans++;
    } else {
      break;
    }
  }
  for (int i = x - 1; i >= 1; i--) {
    if (s.find({i, y}) == s.end()) {
      ans++;
    } else {
      break;
    }
  }
  for (int i = y + 1; i <= n; i++) {
    if (s.find({x, i}) == s.end()) {
      ans++;
    } else {
      break;
    }
  }
  for (int i = y - 1; i >= 1; i--) {
    if (s.find({x, i}) == s.end()) {
      ans++;
    } else {
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (x + i <= n && y + i <= n && s.find({x + i, y + i}) == s.end()) {
      ans++;
    } else {
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (x + i <= n && y - i >= 1 && s.find({x + i, y - i}) == s.end()) {
      ans++;
    } else {
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (x - i >= 1 && y + i <= n && s.find({x - i, y + i}) == s.end()) {
      ans++;
    } else {
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (x - i >= 1 && y - i >= 1 && s.find({x - i, y - i}) == s.end()) {
      ans++;
    } else {
      break;
    }
  }
  cout << ans << "\n";
}