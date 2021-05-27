#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 1;
const int INF = 2e9;

int solve() {
  int n;
  cin >> n;

  if (n == 1) {
    cout << "FastestFinger\n";
    return 0;
  }

  if (n > 1 && n % 2 == 1 || n == 2) {
    cout << "Ashishgup\n";
    return 0;
  }

  int cnt2 = 0;
  while (n % 2 == 0) {
    n /= 2;
    cnt2++;
  }
  if (cnt2 > 1) {
    if (n != 1)
      cout << "Ashishgup\n";
    else
      cout << "FastestFinger\n";
    return 0;
  }
  int cnt = 0;
  for (int i = 3; i <= sqrt(n); i += 2) {
    if (n % i == 0) {
      while (n % i == 0) {
        n /= i;
        cnt++;
      }
    }
  }
  if (n > 1 && n % 2 == 1)
    cnt++;
  if (cnt <= 1) {
    cout << "FastestFinger\n";
  } else {
    cout << "Ashishgup\n";
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