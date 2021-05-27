#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 1;
const int INF = 2e9;

string s = "xcodeforces";
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll k;
  cin >> k;
  for (ll i = 1;; i++) {
    for (ll j = 0; j <= 9; j++) {
      ll cur = 1;
      for (ll k = 1; k <= 10; k++) {
        if (k > j) {
          cur *= i;
        } else
          cur *= (i + 1);
      }
      if (cur >= k) {
        for (ll k = 1; k <= 10; k++) {
          if (k > j) {
            for (int l = 1; l <= i; l++) {
              cout << s[k];
            }
          } else {
            for (int l = 1; l <= i + 1; l++) {
              cout << s[k];
            }
          }
        }
        return 0;
      }
    }
  }
}