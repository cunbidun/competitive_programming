#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, a[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vi l;
  int last = 1;
  for (int i = 2; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      l.push_back(i - last);
      last = i;
    }
  }
  l.push_back(n - last + 1);
  int ans = 0;
  for (int i = 1; i < sz(l); i++) {
    ans = max(ans, min(l[i], l[i - 1]));
  }
  cout << 2 * ans << "\n";
}