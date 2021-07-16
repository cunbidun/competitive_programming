#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, X;
  cin >> N >> X;
  int s = 0;
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    s += x;
    if (i % 2 == 0) {
      s--;
    }
  }
  if (s <= X) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
