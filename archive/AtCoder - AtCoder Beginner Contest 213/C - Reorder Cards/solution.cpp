#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W, N;
  cin >> H >> W >> N;
  vector<array<int, 3>> a(N);
  vector<array<int, 2>> ans(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1];
    a[i][2] = i;
  }
  sort(a.begin(), a.end());

  set<int> mp;
  for (int i = 0; i < N; i++) {

    mp.insert(a[i][0]);
    ans[a[i][2]][0] = mp.size();

  }
  mp.clear();
  sort(a.begin(), a.end(), [](auto A, auto B) { return A[1] < B[1]; });
  for (int i = 0; i < N; i++) {
    mp.insert(a[i][1]);
    ans[a[i][2]][1] = mp.size();
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i][0]  << " " << ans[i][1]  << '\n';
  }
}
