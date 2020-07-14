#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;         
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INFLL = 1e17;
const int N = 2e5 + 5;

int n, a[N];
ll o[N], e[N];
ll sum = 0;
ll sub = INFLL;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    e[i] = e[i - 1];
    o[i] = o[i - 1];
    if (i % 2 == 0) {
      e[i] += a[i];
    }
    if (i % 2 == 1) {
      o[i] += a[i];
    }
    sum += a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      sub = min(sub, o[i] + e[n] - e[i]);
    }
    else {
      sub = min(sub, e[i] + o[n] - o[i]);
    }
  }
  cout << sum - sub << "\n";
}