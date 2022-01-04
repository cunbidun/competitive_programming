#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long N;
  cin >> N;
  if (N == 0) {
    cout << 0 << '\n';
    return 0;
  }
  int negative = 0;
  if (N < 0) {
    negative = 1;
    N = -N;
  }

  long long n1 = N, n2 = 0; // n1 - n2 = N;

  for (long long i = 0; i < 60; i++) {
    if ((n1 >> i) & 1) {
      if (!negative) {
        if (i % 2 == 1 && ((n1 >> i) & 1)) {
          n1 += 1LL << i;
          n2 += 1LL << i;
        }
      } else {
        if (i % 2 == 0 && ((n1 >> i) & 1)) {
          n1 += 1LL << i;
          n2 += 1LL << i;
        }
      }
    }
  }

  if (negative) {
    swap(n1, n2);
  }
  string b = bitset<64>(n1 | n2).to_string(); // to binary
  auto pos = b.find('1');
  cout << b.substr(pos) << '\n';
}
