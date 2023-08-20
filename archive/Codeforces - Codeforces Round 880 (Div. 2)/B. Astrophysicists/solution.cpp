/**
 *  author: cunbidun
 *  created: Sunday, 2023-06-18 09:44:44 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long N, K, G;
    cin >> N >> K >> G;
    long long mn = (G - 1) / 2;
    long long remain = max(K * G - mn * (N - 1), 0LL);
    if (remain % G >= (G + 1) / 2) {
      remain = remain + (G - remain % G);
    } else {
      remain = remain - remain % G;
    }

    cout << K * G - remain << '\n';
  }
}
