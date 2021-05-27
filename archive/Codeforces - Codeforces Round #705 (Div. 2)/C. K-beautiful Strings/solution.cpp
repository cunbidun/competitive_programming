#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n % k != 0) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
    }
    int f = 0;
    for (int i : cnt) {
      f |= (i % k != 0);
    }
    if (!f) {
      cout << s << '\n';
      continue;
    }
    cnt.assign(26, 0);
    int l = -1;
    char c = -1;
    auto check = [&]() -> int {
      vector<int> tmp(26);
      for (int i = 0; i < 26; i++) {
        tmp[i] = (cnt[i] + k - 1) / k * k;
      }
      int sum = 0;
      for (int i : tmp) {
        sum += i;
      }
      return sum <= n;
    };
    for (int i = 0; i < n; i++) {
      for (int j = 25; j >= s[i] - 'a' + 1; j--) {
        cnt[j]++;
        if (check()) {
          l = i;
          c = (char)(j + 'a');
        }
        cnt[j]--;
      }
      cnt[s[i] - 'a']++;
    }
    cnt.assign(26, 0);
    for (int i = 0; i < l; i++) {
      cout << s[i];
      cnt[s[i] - 'a']++;
    }
    cout << c;
    cnt[c - 'a']++;
    int sum = 0;
    for (int i = 0; i < 26; i++) {
      int goal = (cnt[i] + k - 1) / k * k;
      cnt[i] = goal - cnt[i];
      sum += cnt[i];
    }
    cnt[0] += n - sum - l - 1;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < cnt[i]; j++) {
        cout << (char)('a' + i);
      }
    }
    cout << '\n';
  }
}
