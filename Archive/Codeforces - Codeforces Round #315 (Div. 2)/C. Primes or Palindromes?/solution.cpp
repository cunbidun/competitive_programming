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

const int N = 2e6 + 1;
const int INF = 2e9;

vi lp;
vi pr;
void sieve() {
  lp.assign(N, 0);
  for (int i = 2; i < N; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j)
      lp[i * pr[j]] = pr[j];
  }
}

int ch(int n) {
  string tmp = to_string(n);
  string tmp1 = tmp;
  reverse(tmp.begin(), tmp.end());
  return tmp == tmp1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  ll p, q;
  cin >> p >> q;
  ll pi = 0, rub = 0;
  int ans = 0;
  rf(i, 1, N) {
    rub += ch(i);
    pi += (lp[i] == i);
    if (q * pi <= p * rub) {
      ans = i;
      // cout << pi << " " << rub << "\n";
      // return cout << i - 1 << "\n", 0;
    }
  }
  cout << ans << " \n";
}