#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long N;
    cin >> N;
    cout << -(N - 1) << ' ' << N << '\n';
  }
}
