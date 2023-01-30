/**
 *  author: cunbidun
 *  created: Wednesday, 2023-01-25 19:11:48 CST
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
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;
  vector<int> map_index(N);
  map_index[0] = 0;
  string new_s = "";
  new_s.push_back(S[0]);
  for (int i = 1; i < N; i++) {
    if (S[i] == S[i - 1]) {
      map_index[i] = map_index[i - 1];
    } else {
      new_s += S[i];
      map_index[i] = new_s.size() - 1;
    }
  }
  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    L--, R--;
    L = map_index[L];
    R = map_index[R];
    if ((R - L + 1) % 2 == 0) {
      cout << (R - L + 1) / 2 << '\n';
    } else {
      cout << (R - L + 1) / 2 + (new_s[L] != new_s[R]) << '\n';
    }
  }
}
