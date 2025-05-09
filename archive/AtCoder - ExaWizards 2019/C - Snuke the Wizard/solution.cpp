#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, Q;
  cin >> N >> Q;

  string s;
  cin >> s;

  vector<pair<char, char>> spell(Q);
  for (auto &sp : spell)
    cin >> sp.first >> sp.second;

  auto fate = [&](int idx) -> int { // idx is 1‑based
    for (auto [ch, dir] : spell) {
      if (s[idx - 1] == ch) {
        idx += (dir == 'L' ? -1 : 1);
        if (idx == 0)
          return -1; // dropped off left
        if (idx == N + 1)
          return 1; // dropped off right
      }
    }
    return 0; // survived
  };

  int lo = 1, hi = N, L = 0; // L := last index that dies left
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (fate(mid) == -1) {
      L = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }

  lo = 1;
  hi = N;
  int R = N + 1; // R := first index that dies right
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (fate(mid) == 1) {
      R = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << max(0, R - L - 1) << '\n';
  return 0;
}
