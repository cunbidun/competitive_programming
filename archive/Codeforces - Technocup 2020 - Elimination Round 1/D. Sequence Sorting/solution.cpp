#include <bits/stdc++.h>

using namespace std;

template <class T>
struct compressor {
public:
  vector<T> l;
  map<T, int> mp;
  compressor() {}
  void add(T x) {
    l.push_back(x);
  }
  void compress() {
    sort(l.begin(), l.end());
    l.resize(distance(l.begin(), unique(l.begin(), l.end())));
    for (int i : l)
      mp[i] = (int)mp.size() + 1;
  }
  int get(T x) {
    return mp[x];
  }
  int size() {
    return (int)mp.size();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N + 1), last(N + 2, -1), first(N + 2, 1e9);
    compressor<int> c;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      c.add(a[i]);
    }
    c.compress();
    int MX = c.size();
    for (int i = 1; i <= N; i++) {
      a[i] = c.get(a[i]);
      last[a[i]] = max(i, last[a[i]]);
      first[a[i]] = min(i, first[a[i]]);
    }
    vector<int> l(MX + 2, 1e9), r(MX + 2, 1e9);
    l[0] = 0;
    for (int i = 1; i <= MX; i++) {
      if (first[i] < last[i - 1]) {
        l[i] = i - 1;
      } else {
        l[i] = l[i - 1];
      }
    }
    r[MX + 1] = 0;
    for (int i = MX; i >= 1; i--) {
      if (last[i] > first[i + 1]) {
        r[i] = MX - i;
      } else {
        r[i] = r[i + 1];
      }
    }
    int ans = MX - 1;
    for (int i = 1; i <= MX; i++) {
      ans = min(ans, l[i] + r[i]);
    }
    cout << ans << '\n';
  }
}
