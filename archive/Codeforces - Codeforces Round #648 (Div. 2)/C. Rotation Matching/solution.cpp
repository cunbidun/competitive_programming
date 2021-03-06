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

const int N = 2e5 + 1;
const int INF = 2e9;

int n;
int a[N], b[N], p[N];
int ans = 0, cnt[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  rf(i, 1, n) cin >> a[i], p[a[i]] = i;
  rf(i, 1, n) {
    cin >> b[i];
    int cur;
    if (i <= p[b[i]])
      cur = p[b[i]] - i;

    else
      cur = n - i + p[b[i]];
    cnt[cur]++;
    ans = max(ans, cnt[cur]);
  }
	cout << ans << "\n";
}