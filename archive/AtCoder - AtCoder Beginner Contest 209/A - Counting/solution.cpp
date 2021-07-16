#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int A, B;
  cin >> A >> B;
  cout << max(B - A + 1, 0) << "\n";
}
