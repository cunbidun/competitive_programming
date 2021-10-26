#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long A, B, K;
  cin >> K >> A >> B;
  long long a = 0, b = 0;
  {
    long long cur = 1;
    while (A > 0) {
      a += (A % 10) * cur;
      cur *= K;
      A /= 10;
    }
  }

  {
    long long cur = 1;
    while (B > 0) {
      b += (B % 10) * cur;
      cur *= K;
      B /= 10;
    }
  }
  cout << a * b << '\n';
}
