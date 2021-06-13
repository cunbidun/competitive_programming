#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<long long> a(N + 2);
    long long cost = 0;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      cost += abs(a[i] - a[i - 1]);
    }
    cost += a[N];
    for (int i = 1; i <= N; i++) {
      cost -= max(0LL, a[i] - max(a[i - 1], a[i + 1]));
    }
    cout << cost << '\n';
  }
}
