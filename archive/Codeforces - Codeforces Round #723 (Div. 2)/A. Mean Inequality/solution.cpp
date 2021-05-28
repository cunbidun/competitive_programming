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
    vector<int> a(2 * N);
    for (int i = 0; i < 2 * N; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < 2 * N - 1; i += 2) {
      swap(a[i], a[i + 1]);
    }
    for (int i : a) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
