#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  int S = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    S += a[i];
  }
  for (int d = S; d >= 1; d--) {
    if (S % d == 0) {
      int op = 0;
      int s = 0;
      vector<int> tmp;
      for (int i = 0; i < N; i++) {
        int x = a[i] % d;
        tmp.push_back(x);
        s += x;
      }
      sort(tmp.begin(), tmp.end());
      assert(s % d == 0);
      for (int i = 0; i < (int)tmp.size() - s / d; i++) {
        op += tmp[i];
      }
      if (op <= K) {
        cout << d << '\n';
        return 0;
      }
    }
  }
}
