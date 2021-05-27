#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cur = n;
    if (__gcd(a[n - 1], a[0]) != 1) {
      cur = n - 1;
      while (cur > 0) {
        if (__gcd(a[cur - 1], a[cur]) == 1) {
          break;
        }
        cur--;
      }
    }
    vector<list<int>> l;
    l.push_back(list<int>());
    for (int i = max(1, cur); i < n; i++) {
      l[0].push_back(i);
    }
    l[0].push_back(0);
    for (int i = 1; i < cur; i++) {
      if (__gcd(a[i - 1], a[i]) == 1) {
        l.push_back(list<int>());
      }
      l[l.size() - 1].push_back(i);
    }
    vector<int> nxt(l.size());
    for (int i = 0; i < l.size() - 1; i++) {
      nxt[i] = i + 1;
    }
    int sz = l.size();
    cur = 0;
    vector<int> ans;
    while (sz > 1) {
      int last = l[cur].back();
      int first = l[nxt[cur]].front();
      if (__gcd(a[last], a[first]) != 1) {
        l[cur].splice(l[cur].end(), l[nxt[cur]]);
        nxt[cur] = nxt[nxt[cur]];
        sz--;
      } else {
        ans.push_back(l[nxt[cur]].front());
        l[nxt[cur]].pop_front();
        if (l[nxt[cur]].empty()) {
          nxt[cur] = nxt[nxt[cur]];
          sz--;
        }
        cur = nxt[cur];
      }
    }
    while (l[cur].size() > 1 && __gcd(a[l[cur].front()], a[l[cur].back()]) == 1) {
      ans.push_back(l[cur].front());
      l[cur].pop_front();
    }
    if (l[cur].size() == 1 && a[l[cur].front()] == 1) {
      ans.push_back(l[cur].front());
    }
    cout << ans.size() << ' ';
    for (int i : ans) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}
