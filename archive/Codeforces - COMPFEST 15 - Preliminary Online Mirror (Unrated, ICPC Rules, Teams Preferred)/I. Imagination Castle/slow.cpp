
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;
int n, m, k, x[1000001], y[1000001];
int main() {
  cin >> n >> m >> k;
  for (int i = 1, xx, yy; i <= k; i++)
    cin >> xx >> yy, y[xx] = max(y[xx], yy), x[yy] = max(x[yy], xx);
  int yy = m;
  for (int i = n - 1; i >= 1; i--) {
    yy--;
    while (yy && x[yy] > i)
      yy--;
    if (!yy)
      return puts("Chaneka"), 0;
    if (y[i] > yy)
      yy++;
  }
  if (yy == 1)
    puts("Bhinneka");
  else
    puts("Chaneka");
  return 0;
}
