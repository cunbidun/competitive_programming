#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_function(string s) {
  int n = (int)s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = pi[j - 1];
    }
    if (s[j] == s[i]) {
      j++;
    }
    pi[i] = j;
  }
  return pi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = (int)s.size();
  vector<int> ans(n + 1);
  vector<int> pi = prefix_function(s);
  for (int i = 0; i < n; i++) {
    ans[pi[i]]++;
  }
  for (int i = n - 1; i > 0; i--) {
    ans[pi[i - 1]] += ans[i];
  }
  for (int i = 0; i <= n; i++) {
    ans[i]++;
  }
  vector<array<int, 2>> res;
  res.push_back({n, 1});
  int j = pi[n - 1];
  while (j > 0) {
    res.push_back({j, ans[j]});
    j = pi[j - 1];
  }
  reverse(res.begin(), res.end());
  cout << res.size() << "\n";
  for (auto [f, s] : res) {
    cout << f << " " << s << "\n";
  }
}
