#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  vector<int> cnt(26);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char x;
      cin >> x;
      cnt[x - 'a']++;
    }
  }
  for (int i = 0; i < H / 2; i++) {
    for (int j = 0; j < W / 2; j++) {
      int ok = 0;
      for (int k = 0; k < 26; k++) {
        if (cnt[k] >= 4) {
          ok = 1;
          cnt[k] -= 4;
          break;
        }
      }
      if (!ok) {
        cout << "No\n";
        return 0;
      }
    }
  }
  if (H % 2 == 1) {
    for (int i = 0; i < W / 2; i++) {
      int ok = 0;
      for (int k = 0; k < 26; k++) {
        if (cnt[k] >= 2) {
          ok = 1;
          cnt[k] -= 2;
          break;
        }
      }
      if (!ok) {
        cout << "No\n";
        return 0;
      }
    }
  }
  if (W % 2 == 1) {
    for (int i = 0; i < H / 2; i++) {
      int ok = 0;
      for (int k = 0; k < 26; k++) {
        if (cnt[k] >= 2) {
          ok = 1;
          cnt[k] -= 2;
          break;
        }
      }
      if (!ok) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
}
