#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, d12, d23, d31;
    cin >> N >> d12 >> d23 >> d31;
    if ((d12 + d23 + d31) % 2 != 0) {
      cout << "NO\n";
      continue;
    }
    int d3 = (d12 + d23 + d31) / 2 - d12;
    int d2 = d23 - d3;
    int d1 = d31 - d3;
    if (d1 < 0 || d2 < 0 || d3 < 0) {
      cout << "NO\n";
      continue;
    }
    if (d1 == 0 && d2 == 0) {
      cout << "NO\n";
      continue;
    }
    if (d1 == 0 && d3 == 0) {
      cout << "NO\n";
      continue;
    }
    if (d2 == 0 && d3 == 0) {
      cout << "NO\n";
      continue;
    }
    if (d1 + d2 + d3 + 1 > N) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int r = 4;
    if (d1 == 0) {
      r = 1;
    }
    if (d2 == 0) {
      r = 2;
    }
    if (d3 == 0) {
      r = 3;
    }
    int last = r;
    int cnt = 4;
    if (cnt == last) {
      cnt++;
    }
    if (d1) {
      for (int i = 0; i < d1 - 1; i++) {
        cout << last << ' ' << cnt << '\n';
        last = cnt;
        cnt++;
      }
      cout << last << ' ' << 1 << '\n';
    }
    last = r;
    if (d2) {
      for (int i = 0; i < d2 - 1; i++) {
        cout << last << ' ' << cnt << '\n';
        last = cnt;
        cnt++;
      }
      cout << last << ' ' << 2 << '\n';
    }
    last = r;
    if (d3) {
      for (int i = 0; i < d3 - 1; i++) {
        cout << last << ' ' << cnt << '\n';
        last = cnt;
        cnt++;
      }
      cout << last << ' ' << 3 << '\n';
    }
    while (cnt <= N) {
      if (r != cnt) {
        cout << r << ' ' << cnt << '\n';
      }
      cnt++;
    }
  }
}
