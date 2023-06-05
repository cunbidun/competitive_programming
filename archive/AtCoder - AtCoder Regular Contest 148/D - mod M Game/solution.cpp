/**
 *  author: cunbidun
 *  created: Monday, 2023-05-01 23:42:44 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<int> a(2 * N);
  map<int, int> cnt;
  for (int i = 0; i < 2 * N; i++) {
    cin >> a[i];
    cnt[a[i]] += 1;
  }
  for (int i = 0; i < 2 * N; i++) {
    cnt[a[i]] %= 2;
    if (M % 2 == 1 && cnt[a[i]] != 0) {
      cout << "Alice\n";
      exit(0);
    }
  }
  int blue = 0;
  if (M % 2 == 0) {
    for (int i = 0; i < 2 * N; i++) {
      if (a[i] < M / 2) {
        if (cnt[a[i]] > 0 && cnt[a[i] + M / 2] > 0) {
          blue++;
        } else if (cnt[a[i]] == 0 && cnt[a[i] + M / 2] == 0) {

        } else {
          cout << "Alice\n";
          exit(0);
        }
      }
    }
  }
  // cout << blue << '\n';
  if (blue % 2 == 0) {
    cout << "Bob\n";
  } else {
    cout << "Alice\n";
  }
}
