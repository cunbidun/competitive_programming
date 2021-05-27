#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    vector<int> cntl(n + 1), cntr(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i < l) {
        cntl[a[i]]++;
      } else {
        cntr[a[i]]++;
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int d = min(cntl[i], cntr[i]);
      cntl[i] -= d;
      cntr[i] -= d;
      r -= d;
      l -= d;
    }
    if (r < l) {
      swap(l, r);
      swap(cntl, cntr);
    }
    int limit = (r - l) / 2;
    int have = 0;
    for (int i = 1; i <= n; i++) {
      have += cntr[i] / 2;
    }
    ans += min(have, limit);
    r -= 2 * min(have, limit);

    // if min = have: which mean all the sock on the right are reduce to
    // either 0 or 1. Because of the number of sock on the right are >= 
    // the number of sock on the left, we first move the sock on the right
    // side to match socks on the left (this takes r - l opterations). After that
    // we left with only l socks on the right . Because there is at most 1 sock for 
    // each color on the right, we need to change half of them to left sock with 
    // correct color (this take l opterations). In total, this take r opterations 
   
    // if min = limit: which mean the number of socks on the right are 
    // equal to the left. In this case, we just need to move sock on right
    // to match the color on the left (need r opteration in total)
   
    ans += r;
    cout << ans << '\n';
  }
}
