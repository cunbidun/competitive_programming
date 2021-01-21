#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e4;

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
  int d;
  cin >> d;
  vi l;
  for (int i : pr) {
    if (sz(l) == 2) {
      break;
    }
    if (sz(l) == 0 && i >= d + 1) {
      l.push_back(i);
    }
    if (sz(l) == 1 && i >= l[0] + d) {
      l.push_back(i);
    }
  }
  cout << 1LL * l[0] * l[1] << "\n";
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
