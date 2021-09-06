#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int ans = 1e9;
  for (int i = 0; i < N; i++) {
    vector<int> v;
    for (int j = 0; j < i ;j++) {
      v.push_back(a[j]);
    }
    for (int j = i + K; j < N ;j++) {
      v.push_back(a[j]);
    }
    ans = min(*max_element(v.begin(), v.end()) - *min_element(v.begin(),v.end()), ans);
  }
  cout << ans << '\n';
}
