#include <array>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <int MXBIT, class T> struct trie_bit {
  int id;
  vector<array<int, 2>> trie;
  vector<int> val;
  trie_bit(int _sz) : id(1), trie(vector<array<int, 2>>(_sz)), val(vector<int>(_sz)) {}

  void add(T n, int val_id) {
    int cur = 1;
    for (int i = MXBIT - 1; i >= 0; i--) {
      int b = (n >> i) & 1;
      if (trie[cur][b] == 0) {
        trie[cur][b] = ++id;
      }
      cur = trie[cur][b];
    }
    val[cur] = val_id;
  }

  array<int, 2> get_max(T n) {
    int cur = 1;
    int ans = 0;
    for (int i = MXBIT - 1; i >= 0; i--) {
      int b = (n >> i) & 1;
      if (trie[cur][1 - b] != 0) {
        ans ^= (1 << i);
        cur = trie[cur][1 - b];
      } else {
        cur = trie[cur][b];
      }
    }
    return {ans, val[cur]};
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  if (K == 0) {
    cout << N << '\n';
    for (int i = 1; i <= N; i++) {
      cout << i << ' ';
    }
    cout << '\n';
    return 0;
  }
  map<int, vector<array<int, 2>>> mp;
  int mask = (1 << 30) - 1;
  for (int i = 0; i <= 29; i++) {
    if ((1 << i) <= K) {
      mask ^= (1 << i);
    }
  }
  for (int i = 0; i < N; i++) {
    int val = mask & a[i];
    if (mp.find(val) == mp.end()) {
      mp[val] = {};
    }
    mp[val].push_back({a[i], i});
  }
  vector<int> ans;
  for (auto [_, l] : mp) {
    trie_bit<30, int> trie(30 * ((int)l.size() + 5));
    bool found = false;
    for (auto [v, i] : l) {
      trie.add(v, i);
      auto [value, index] = trie.get_max(v);
      if (value >= K) {
        ans.push_back(i);
        ans.push_back(index);
        found = true;
        break;
      }
    }
    if (!found) {
      ans.push_back(l[0][1]);
    }
  }
  if (ans.size() < 2) {
    cout << -1 << '\n';
    return 0;
  }
  cout << ans.size() << '\n';
  for (int i : ans) {
    cout << i + 1 << ' ';
  }
  cout << '\n';
}
