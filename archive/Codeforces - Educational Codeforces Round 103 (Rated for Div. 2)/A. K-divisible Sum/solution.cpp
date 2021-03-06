#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long n, k;
    cin >> n >> k;
    if (k < n) {
      k *= (n + k - 1) / k;
    }
    cout << (k + n - 1) / n << "\n";
  }
}
