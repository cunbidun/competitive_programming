#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(long long l, long long r) {
  cout << l << " " << r << endl;
  string res;
  cin >> res;
  if (res == "Bad") {
    exit(0);
  }
  return res == "Yes";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long n, k;
  cin >> n >> k;
  long long l = 1, r = n;
  while (1) {
    if (r - l > 50) {
      ll m = (l + r) / 2;
      if (ask(l, m)) {
        r = min(n, m + k);
        l = max(l - k, 1LL);
      } else {
        l = max(m - k, 1LL);
        r = min(n, r + k);
      }
    } else {
      ll p = rng() % (r - l + 1) + 1;
      if (ask(l + p - 1, l + p - 1)) {
        return 0;
      }
      r = min(n, r + k);
      l = max(1LL, l - k);
    }
  }
}
