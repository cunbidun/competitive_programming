#include <bits/stdc++.h>

using namespace std;

int n;
pair<int, int> a[100005];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    a[i] = {x, i};
  }
  sort(a + 1, a + n + 1, greater<>());
  
	int cur_day = 1;
  for (int i = 1; i <= n; i++) {
    while (cur_day < a[i].second) {
      cout << "\n";
      cur_day++;
    }
    cout << a[i].first << " ";
  }
}