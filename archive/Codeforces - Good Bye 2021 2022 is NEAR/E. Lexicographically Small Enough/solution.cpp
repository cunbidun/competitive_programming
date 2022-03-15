#include <bits/stdc++.h>

using namespace std;

// fenwick_tree
// 1-based index
template <typename T> struct fenwick_tree {
  vector<T> bit;
  int n;
  fenwick_tree() {}
  fenwick_tree(int _n) { init(_n); }
  void init(int _n) { n = _n, bit.assign(n + 1, T{}); }
  void update(int p, T v) {
    while (p <= n) {
      bit[p] += v, p += p & -p;
    }
  }
  T get(int p) {
    T res{};
    while (p >= 1) {
      res += bit[p], p -= p & -p;
    }
    return res;
  }
  T get(int l, int r) { return (l > r) ? T{} : get(r) - get(l - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    string s, t;
    cin >> s >> t;

    // change to 1-based index
    s = '*' + s;
    t = '*' + t;

    // calculate the vector of location
    vector<queue<int>> loc(26);
    for (int i = 1; i <= N; i++) {
      loc[s[i] - 'a'].push(i);
    }

    // current pointer
    vector<int> pointer(26, 1);

    // bool array to check if character is used or not
    vector<bool> used(N + 1, 0);

    long long ans = 1e18;
    long long prefix_move = 0;

    fenwick_tree<long long> fw(N);
    // for each prefix length
    for (int i = 0; i < N; i++) {
      if (i != 0) {
        // cannot create a prefix with length i
        if (loc[t[i] - 'a'].empty()) {
          break;
        }
        int pos = loc[t[i] - 'a'].front();
        // cout << t[i] << ' ' << pos << " " << i << " "
        //      << max(0, pos - i - fw.get(i, pos)) << '\n';
        prefix_move += max(0LL, pos + fw.get(pos, N) - i);
        fw.update(pos, 1);
        used[pos] = true;
        loc[t[i] - 'a'].pop();
        // cout << prefix_move << '\n';
      }

      int index = t[i + 1] - 'a';
      while (pointer[index] <= N) {
        if (!used[pointer[index]] && s[pointer[index]] < t[i + 1]) {
          break;
        }
        pointer[index]++;
      }

      // cannot find the next smaller
      if (pointer[index] > N) {
        continue;
      }
      // move = move to create prefix + move to correct the last
      long long correct_move =
          max(0LL, pointer[index] + fw.get(pointer[index], N) - (i + 1));

      // cout << correct_move << '\n';
      ans = min(ans, correct_move + prefix_move);
    }
    if (ans == 1e18) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}
