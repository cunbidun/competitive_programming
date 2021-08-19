#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<int, 2>> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i][0];
    a[i][1] = i;
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  cout << a[1][1] + 1 << '\n';
}
