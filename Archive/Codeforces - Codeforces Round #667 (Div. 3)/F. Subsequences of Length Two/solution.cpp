#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string t, s;
  cin >> s >> t;
  if (t[0] == t[1]) {
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] != t[0]) {
        cnt++;
      }
    }
    int total = n - cnt + min(cnt, k);
    cout << 1LL * total * (total - 1) / 2 << '\n';
    return 0;
  }
  s = ' ' + s;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == t[0]) {
      a[i] = 0;
    } else if (s[i] == t[1]) {
      a[i] = 1;
    } else {
      a[i] = 2;
    }
  }
  vector<vector<int>> cnt(n + 1, vector<int>(3, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      cnt[i][j] = cnt[i - 1][j];
    }
    cnt[i][a[i]]++;
  }

  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      vector<int> b = a;
      int r = j;
      deque<int> p0, p1, p2;
      for (int l = 1; l <= i; l++) {
        if (b[l] == 1) {
          p1.push_back(l);
        } else if (b[l] == 2) {
          p2.push_back(l);
        }
      }

      while (r) {
        if (p1.size() == 0 && p2.size() == 0) {
          break;
        }
        if (p1.size() == 0) {
          b[p2.front()] = 0;
          p2.pop_front();
        } else if (p2.size() == 0) {
          b[p1.front()] = 0;
          p1.pop_front();
        } else {
          int n1 = cnt[i][1] - cnt[p1.front()][1] - (p1.front() - 1);
          int n2 = cnt[i][1] - cnt[p2.front()][1];
          if (n1 > n2) {
            b[p1.front()] = 0;
            p1.pop_front();
          } else {
            b[p2.front()] = 0;
            p2.pop_front();
          }
        }
        r--;
      }
      r = k - j;
      p2.resize(0);
      for (int l = n; l > i; l--) {
        if (b[l] == 0) {
          p0.push_back(l);
        } else if (b[l] == 2) {
          p2.push_back(l);
        }
      }
      while (r) {
        if (p0.size() == 0 && p2.size() == 0) {
          break;
        }
        if (p0.size() == 0) {
          b[p2.front()] = 1;
          p2.pop_front();
        } else if (p2.size() == 0) {
          b[p0.front()] = 1;
          p0.pop_front();
        } else {
          int n0 = cnt[p0.front()][0] - cnt[i][0] - (p0.front() - 1);
          int n2 = cnt[p2.front()][0] - cnt[i][0];
          if (n0 > n2) {
            b[p0.front()] = 1;
            p0.pop_front();
          } else {
            b[p2.front()] = 1;
            p2.pop_front();
          }
        }
        r--;
      }
      long long res = 0;
      int c0 = 0;
      for (int l = 1; l <= n; l++) {
        if (b[l] == 1) {
          res += c0;
        }
        if (b[l] == 0) {
          c0++;
        }
      }
      ans = max(ans, res);
    }
  }
  cout << ans << '\n';
}
