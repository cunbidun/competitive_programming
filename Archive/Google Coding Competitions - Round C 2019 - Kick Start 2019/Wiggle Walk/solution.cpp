#include <bits/stdc++.h>

using namespace std;

struct ds {
  set<pair<int, int>> s;
  ds() {
    s.clear();
    s.insert({-2, -2});
    s.insert({2e9, 2e9});
  }
  void insert(int i) {
    auto it = s.upper_bound({i, 1e9});
    auto b = it;
    b--;
    if (i + 1 == it->first && i == b->second + 1) {
      s.erase(it);
      s.erase(b);
      s.insert({b->first, it->second});
    } else if (i + 1 == it->first) {
      s.erase(it);
      s.insert({i, it->second});
    } else if (i == b->second + 1) {
      s.erase(b);
      s.insert({b->first, i});
    } else {
      s.insert({i, i});
    }
  }

  int get_lower(int i) {
    auto it = s.upper_bound({i, 1e9});
    it--;
    return it->first - 1;
  }

  int get_higher(int i) {
    auto it = s.upper_bound({i, 1e9});
    it--;
    return it->second + 1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, R, C, S_R, S_C;
    cin >> N >> R >> C >> S_R >> S_C;
    S_R--;
    S_C--;
    vector<ds> row(R), col(C);
    row[S_R].insert(S_C);
    col[S_C].insert(S_R);
    while (N--) {
      char c;
      cin >> c;
      if (c == 'N') {
        S_R = col[S_C].get_lower(S_R);
      } else if (c == 'S') {
        S_R = col[S_C].get_higher(S_R);
      } else if (c == 'E') {
        S_C = row[S_R].get_higher(S_C);
      } else {
        S_C = row[S_R].get_lower(S_C);
      }
      row[S_R].insert(S_C);
      col[S_C].insert(S_R);
    }
    cout << S_R + 1 << ' ' << S_C + 1 << '\n';
  }
}
