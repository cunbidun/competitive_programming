/**
 *  author: cunbidun
 *  created: Sunday, 2023-06-04 10:02:39 CDT
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
    int N;
    cin >> N;
    vector<int> a(N + 1);
    int p1 = -1;
    int p2 = -1;
    int pN = -1;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        p1 = i;
      }
      if (a[i] == 2) {
        p2 = i;
      }
      if (a[i] == N) {
        pN = i;
      }
    }
    if (abs(p1 - p2) == 1) {
      if (p1 < pN) {
        if (p1 < p2) {
          cout << p2 << ' ' << pN << '\n';
        } else {
          cout << p1 << ' ' << pN << '\n';
        }
      } else {

        if (p1 < p2) {
          cout << p1 << ' ' << pN << '\n';
        } else {
          cout << p2 << ' ' << pN << '\n';
        }
      }
    } else {
      if (p1 < p2) {
        cout << p1 + 1 << ' ' << pN << '\n';
      } else {
        cout << p2 + 1 << ' ' << pN << '\n';
      }
    }
  }
}
