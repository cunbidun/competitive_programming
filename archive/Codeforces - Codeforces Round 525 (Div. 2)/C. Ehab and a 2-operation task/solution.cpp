#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

#define ll long long
#define pb push_back
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 2e3 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n;
ll a[MAXA];

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
#endif
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll curr = n;
  cout << n + 1 << endl;
  ll track = 0;
  for (int i = n; i >= 1; i--) {
    ll temp = (a[i] + track) % (n + 1);
    cout << 1 << " " << i << " " << curr + n + 1 - temp << endl;
    track += curr - temp;
    curr--;
    // cout << (a[i] + track) % (n + 1) << endl;
  }
  cout << 2 << " " << n << " " << n + 1 << endl;
  return 0;
}
