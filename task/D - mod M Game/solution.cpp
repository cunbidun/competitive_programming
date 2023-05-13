/**
 *  author: cunbidun
 *  created: Monday, 2023-05-01 23:42:44 CDT
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
  int N, M;
  cin >> N >> M;
  vector<int> a(2 * N);
  for (int i = 0; i < 2 * N; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long s1 = 0, s2 = 0;
  for (int i = 2 * N - 1; i >= 1; i -= 2) {
    s1 += a[i];
    s2 += a[i - 1];
  }
  if (s1 != s2) {
    cout << "Alice\n";
  } else {
    cout << "Bob\n";
  }
}
