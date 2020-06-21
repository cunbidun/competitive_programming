#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 1;
const int INF = 2e9;

int n;
int a[N];
int solve() {
  cin >> n;
  vector<ii> odd, even;
  for (int i = 1; i <= 2 * n; i++) {
    cin >> a[i];
    if (a[i] % 2 == 1)
      odd.push_back({a[i], i});
    else
      even.push_back({a[i], i});
  }
  if (sz(odd) % 2 == 1) {
    odd.pop_back();
    even.pop_back();
  } else {
    if (sz(odd) >= 2) {
      odd.pop_back();
      odd.pop_back();
    } else {
      even.pop_back();
      even.pop_back();
    }
  }
  for (int i = 0; i < sz(odd); i += 2) {
    cout << odd[i].second << " " << odd[i + 1].second << "\n";
  }

  for (int i = 0; i < sz(even); i += 2) {
    cout << even[i].second << " " << even[i + 1].second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
}