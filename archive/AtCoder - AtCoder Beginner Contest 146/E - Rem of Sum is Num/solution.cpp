#include <array>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<int> a(N + 1);
  vector<int> s(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    a[i]--;
    s[i] = (s[i - 1] + a[i]) % K;
  }
  long long ans = 0;
  int p = 0;
  map<int, int> cnt;
  cnt[0] = 1;
  for (int i = 1; i <= N; i++) {
    while (i - p >= K) {
      cnt[s[p]]--;
      p++;
    }
    ans += cnt[s[i]];
    cnt[s[i]]++;
  }
  cout << ans << '\n';
}
