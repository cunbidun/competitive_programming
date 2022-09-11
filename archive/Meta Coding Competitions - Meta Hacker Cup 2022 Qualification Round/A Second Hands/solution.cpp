#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    int mx = 0;
    vector<int> cnt(104);
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      cnt[x] += 1;
      mx = max(mx, cnt[x]);
    }
    if (N > 2 * K || mx > 2) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
