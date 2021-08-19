#include <bits/stdc++.h>
using namespace std;

int c[1005][1005];
int main() {
  int a, b, max1 = 0;
  cin >> a >> b;
  for (int i = 0; i <= a + 1; i++)
    for (int e = 0; e <= b + 1; e++) {
      c[i][e] = 0;
      if (i > 0 && e > 0 && i < a + 1 && e < b + 1)
        cin >> c[i][e];
    }
  for (int e = 1; e <= b; e++) {
    int max2 = c[1][e];
    int u = e;
    for (int i = 2; i <= a; i++) {
      if (c[i][u] > c[i][u - 1] && c[i][u] > c[i][u + 1])
        max2 += c[i][u];
      else if (c[i][u + 1] > c[i][u - 1] && c[i][u + 1] > c[i][u]) {
        u++;
        max2 += c[i][u];
      } else {
        u--;
        max2 += c[i][u];
      }
    }
    max1 = max(max1, max2);
  }
  cout << max1;
}
