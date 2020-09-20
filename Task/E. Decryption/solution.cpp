#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
vi lp;
vi pr;
void sieve() {
  lp.assign(N, 0);
  for (int i = 2; i < N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j) {
      lp[i * pr[j]] = pr[j];
    }
  }
}

void solve() {
  int n;
  cin >> n;
  vi l;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      l.push_back(i);
      if (i != n / i) {
        l.push_back(n / i);
      }
    }
  }
  l.push_back(n);
  if (sz(l) <= 2) {
    cout << 0 << "\n";
    for (int i : l) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  if (sz(l) == 3) {
    if (l[1] % l[0] == 0) {
      cout << 0 << "\n";
    } else {
      cout << 1 << "\n";
    }
    for (int i : l) {
      cout << i << " ";
    }
    cout << "\n";
    return;
  }
  cout << 0 << "\n";
  
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}