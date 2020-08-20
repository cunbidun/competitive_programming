#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;

int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = (1LL * ans * i) % MOD;
  }
  int sub = 1;
  for (int i = 1; i <= n - 1; i++) {
    sub = (1LL * sub * 2) % MOD;
  }
  cout << ((ans - sub) % MOD + MOD) % MOD << "\n";
}