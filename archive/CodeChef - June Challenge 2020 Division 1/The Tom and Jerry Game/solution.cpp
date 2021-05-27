#include <bits/stdc++.h>
using namespace std;

#define ll long long

int solve() {
  ll TS;
  cin >> TS;
  ll tmp = TS;
  int cnt = 1;
  while (tmp % 2 == 0) {
    tmp /= 2;
    cnt++;
  }
  ll first = 1LL << cnt;
  cout << TS / first << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--) solve();
}