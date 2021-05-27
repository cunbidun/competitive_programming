#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll t, b, w, tot;
  cin >> t >> w >> b;
  if (w > b) swap(w, b);
  if (t / b < w / __gcd(b, w)) {
    tot = min(w-1, t);
  } else {
    ll x = b / __gcd(b, w) * w;
    // cout << x << " " << t / x * w << "\n";
    tot = t / x * w + min(w, t % x + 1)-1;
  }
  ll d = __gcd(tot, t);
  cout << tot / d << "/" << t / d << "\n";
}