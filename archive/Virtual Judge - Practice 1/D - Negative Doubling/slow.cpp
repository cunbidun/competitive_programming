#include <array>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  long long ans = 1e18;
  auto cal = [&](vector<int> v) -> long long {
    int total = 0;
    int last = 0;
    for (int i = 1; i < (int)v.size(); i++) {
      int cnt = 0;
      long long mx = v[i];
      while (mx < v[i - 1]) {
        cnt += 2;
        mx *= 4;
      }
      if (cnt == 0) {
        mx = v[i - 1];
        while (mx <= v[i]) {
          cnt += 2;
          mx *= 4;
        }
        cnt -= 2;
        last = max(0, last - cnt);
      } else {
        last = last + cnt;
      }
      total += last;
    }
    return total;
  };
  for (int i = 1; i <= N + 1; i++) {
    vector<int> l, r;
    for (int j = 1; j < i; j++) {
      l.push_back(2 * a[j]);
    }
    reverse(l.begin(), l.end());
    for (int j = i; j <= N; j++) {
      r.push_back(a[j]);
    }
    ans = min(ans, cal(l) + (int)l.size() + cal(r));
  }
  cout << ans << '\n';
}
