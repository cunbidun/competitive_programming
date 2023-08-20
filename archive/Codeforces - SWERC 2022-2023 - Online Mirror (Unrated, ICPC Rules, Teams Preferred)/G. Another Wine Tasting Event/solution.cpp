/**
 *  author: cunbidun
 *  created: Thursday, 2023-07-27 21:36:45 CDT
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
  int N;
  cin >> N;
  string S;
  cin >> S;
  int cnt = 0;
  int mx = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == 'W') {
      cnt++;
    }
  }
  mx = cnt;
  for (int i = N; i < 2 * N - 1; i++) {
    cnt += (S[i] == 'W');
    cnt -= (S[i - N] == 'W');
    mx = max(cnt, mx);
  }
  cout << mx << '\n';
}
