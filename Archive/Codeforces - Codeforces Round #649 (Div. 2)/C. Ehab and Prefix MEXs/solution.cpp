#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

int n;
int a[N], ans[N];
set<int> s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ans[i] = -1;
    cin >> a[i];
  }
  ans[1] = a[1] - 1;
  s.insert(ans[1]);
  s.insert(a[n]);
  for (int i = 2; i <= n; i++) {
    if (a[i] != a[i - 1]) {
      ans[i] = a[i - 1];
      s.insert(ans[i]);
    }
  }
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    if (ans[i] == -1) {
      while (s.find(cur) != s.end()) {
        cur++;
      }
      ans[i] = cur;
      s.insert(ans[i]);
    }
  }
  s.clear();
  cur = 0;
  for (int i = 1; i <= n; i++) {
    s.insert(ans[i]);
    while (s.find(cur) != s.end()) {
      cur++;
    }
    if (cur != a[i]) {
      cout << "-1\n";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";

  if (1) {
    cout << ans[1] << " ";
  }
}