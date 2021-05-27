#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int wc, hc, ws, hs;
  cin >> wc >> hc >> ws >> hs;
  if (wc - 2 >= ws && hc - 2 >= hs) {
    cout << 1 << '\n';
    return 0;
  }
  cout << 0 << '\n';
  return 0;
}
