#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int n, ans[805];
vector<pair<int, ii>> l;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  n *= 2;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      int x;
      cin >> x;
      l.push_back({x, {i, j}});
    }
  }
  sort(all(l));
  reverse(all(l));
  for (int i = 0; i < sz(l); i++) {
    int a = l[i].second.first;
    int b = l[i].second.second;
    if (ans[a] == 0 && ans[b] == 0) {
      ans[a] = b;
      ans[b] = a;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}