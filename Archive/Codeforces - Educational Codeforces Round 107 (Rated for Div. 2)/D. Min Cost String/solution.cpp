#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string res = "";
  for (char i = 'a'; i <= (char)('a' + k - 1); i++) {
    if (i != 'a') {
      res += i;
      res += i;
    }
    for (char j = 'b'; j < i; j++) {
      res += j;
      res += i;
    }
    res += 'a';
  }
  cout << 'a';
  n--;
  while (n > res.size()) {
    cout << res;
    n -= res.size();
  }
  for (int i = 0; i < n; i++) {
    cout << res[i];
  }
  cout << '\n';
}
