#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  string S;
  cin >> S;
  if (S.front() != S.back()) {
    cout << 1 << '\n';
    return 0;
  }
  for (int i = 1; i <= (int)S.size() - 3; i++) {
    if (S[i] != S[0] && S[i + 1] != S[0]) {
      cout << 2 << '\n';
      return 0;
    }
  }
  cout << "-1\n";
}
