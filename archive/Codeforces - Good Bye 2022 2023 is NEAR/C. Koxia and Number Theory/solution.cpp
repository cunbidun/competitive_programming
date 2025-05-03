#include <bits/stdc++.h>
#include <unistd.h>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<long long> a(N);
    set<long long> s;
    int f = 0;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      if (s.find(a[i]) != s.end()) {
        f = 1;
      }
      s.insert(a[i]);
    }
    for (int i = 2; i <= 55; i++) {
      vector<long long> r(i);
      for (long long j : a) {
        r[j % i] += 1;
      }
      int cnt = 0;
      for (long long j : r) {
        if (j > 1) {
          cnt += 1;
        }
      }
      if (cnt == i) {
        f = 1;
        break;
      }
    }
    if (f) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
