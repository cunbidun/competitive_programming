#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 1;
string s, t;
int p[N], c[N], lcp[N];

void radix_sort(vector<pair<ii, int>> &a) {
  int n = sz(a);
  vector<int> cnt(n);
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cnt[a[i].first.first]++;
  }
  p[0] = 0;
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] + cnt[i - 1];
  }
  vector<pair<ii, int>> new_a(n);
  for (int i = 0; i < n; i++) {
    new_a[p[a[i].first.first]] = a[i];
    p[a[i].first.first]++;
  }
  a = new_a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s >> t;
  s = s + (char)129 + t + "$";
  int n = sz(s);
  vector<pair<char, int>> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = {s[i], i};
  }
  sort(all(a));
  for (int i = 0; i < n; i++) {
    p[i] = a[i].second;
  }
  c[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i].first == a[i - 1].first) {
      c[p[i]] = c[p[i - 1]];
    } else {
      c[p[i]] = c[p[i - 1]] + 1;
    }
  }
  int k = 0;
  while ((1 << k) < n) {
    vector<pair<ii, int>> a(n);
    for (int i = 0; i < n; i++) {
      int prev = (p[i] - (1 << k) + n) % n;
      a[i] = {{c[prev], c[p[i]]}, prev};
    }
    radix_sort(a);
    for (int i = 0; i < n; i++) {
      p[i] = a[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++) {
      if (a[i].first == a[i - 1].first) {
        c[p[i]] = c[p[i - 1]];
      } else {
        c[p[i]] = c[p[i - 1]] + 1;
      }
    }
    k++;
  }

  k = 0;

  for (int i = 0; i < n - 1; i++) {
    k = max(0, k - 1);
    while (s[i + k] == s[p[c[i] - 1] + k]) {
      k++;
    }
    lcp[c[i] - 1] = k;
  }
  int b = sz(s) - sz(t) - 2;
  int mx = 0, pos = 0;
  for (int i = 1; i < n; i++) {
    if ((p[i] < b && p[i - 1] > b) || (p[i] > b && p[i - 1] < b)) {
      if (lcp[i - 1] > mx) {
        mx = lcp[i - 1];
        pos = p[i];
      }
    }
  }
  cout << s.substr(pos, mx) << "\n";
}