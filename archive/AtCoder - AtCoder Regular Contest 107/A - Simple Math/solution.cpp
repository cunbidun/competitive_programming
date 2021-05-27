#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
int MOD = 998244353;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c;
  cin >> a >> b >> c;
  a = (a * (a + 1) / 2) % MOD;
  b = (b * (b + 1) / 2) % MOD;
  c = (c * (c + 1) / 2) % MOD;
  cout << ((a * b) % MOD * c) % MOD << "\n";
}