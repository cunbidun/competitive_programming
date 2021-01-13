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
  int n;
  cin >> n;
  int c2 = 0, c5 = 0;
  for (int i = 2; i <= n; i *= 2) {
    c2 += n / i;
  }
  for (int i = 5; i <= n; i *= 5) {
    c5 += n / i;
  }
  cout << min(c2, c5) << "\n";
}
