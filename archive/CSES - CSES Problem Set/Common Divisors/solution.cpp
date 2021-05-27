#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e6 + 6;
int n, cnt[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        cnt[j]++;
        if (x / j != j) {
          cnt[x / j]++;
        }
      }
    }
  }
  for (int i = 1000000; i >= 1; i--) {
    if (cnt[i] >= 2) {
      cout << i << "\n";
      return 0;
    }
  }
}
