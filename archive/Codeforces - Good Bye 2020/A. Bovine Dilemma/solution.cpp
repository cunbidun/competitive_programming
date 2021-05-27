#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e2 + 5;
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    set<int> s;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        s.insert(abs(a[i] - a[j]));
      }
    }
    cout << sz(s) << "\n";
  }
}
