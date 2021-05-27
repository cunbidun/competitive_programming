#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;

string s;
int p[N], c[N];

void radix_sort(vector<pair<ii, int>> &a) {
  int n = sz(a);
  vector<pair<ii, int>> new_a(n);
  vi cnt(n), pos(n);
  for (int i = 0; i < n; i++) {
    cnt[a[i].first.first]++;
  }
  pos[0] = 0;
  for (int i = 1; i < n; i++) {
    pos[i] = pos[i - 1] + cnt[i - 1];
  }
  for (int i = 0; i < n; i++) {
    new_a[pos[a[i].first.first]] = a[i];
    pos[a[i].first.first]++;
  }
  a = new_a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> s;
  s += '$';
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
      a[i] = {{c[(p[i] - (1 << k) + n) % n], c[p[i]]}, (p[i] - (1 << k) + n) % n};
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

  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    int l = 1, r = n - 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (s.substr(p[m], sz(t)) < t) {
        l = m + 1;
      } else if (s.substr(p[m], sz(t)) > t) {
        r = m - 1;
      } else {
        l = m,
        r = m;
      }
    }
    if (s.substr(p[l], sz(t)) == t) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}