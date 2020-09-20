#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 100005;
int n, a[N], ans[N], used[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= (n - 1) / 2; i++) {
    ans[i * 2] = a[i];
    used[i] = 1;
  }
  int cur = 1;
  for (int i = (n - 1) / 2 + 1; i <= n; i++) {
    if (a[i] > ans[cur + 1]) {
      ans[cur] = a[i];
      cur += 2;
      used[i] = 1;
    }
    if (cur + 1 > n) {
      break;
    }
  }
  int cnt = 0;
  cur = 1;
  for (int i = 1; i <= n; i++) {
    while (used[cur] && cur <= n) {
      cur++;
    }
    if (ans[i] == 0) {
      ans[i] = a[cur];
      cur++;
    }
  }
  for (int i = 2; i < n; i++) {
    if (ans[i - 1] > ans[i] && ans[i] < ans[i + 1]) {
      cnt++;
    }
  }
  cout << cnt << "\n";
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}